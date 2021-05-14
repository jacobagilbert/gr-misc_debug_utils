#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2016 <+YOU OR YOUR COMPANY+>.
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

import numpy
import pmt
from gnuradio import gr

class dropped_samp_detector(gr.sync_block):
    """
    docstring for block dropped_samp_detector
    """
    def __init__(self):
        gr.sync_block.__init__(self,
            name="dropped_samp_detector",
            in_sig=[numpy.complex64],
            out_sig=None)

        self.rate = 1000000     # this will get overwritten by samp 0 tag
        self.base_time = 0      # this will get overwritten by samp 0 tag


    def work(self, input_items, output_items):
        nitems = input_items[0].size
        start = self.nitems_read(0)
        end = start + nitems

        # get tags
        tags = self.get_tags_in_range(0, start, end)

        # first go through and check for rx_time tags
        for tag in tags:
            if pmt.equal(tag.key, pmt.intern('rx_time')):
                # on the first sample, don't check for errors
                if tag.offset == 0:
                    self.base_time = sum(pmt.to_python(tag.value))
                    print ("first tag " + repr(tag.value) + ", base_time set to " + repr(self.base_time))

                # other times we get this, check for errors
                else:
                    time = sum(pmt.to_python(tag.value))
                    samp = (time - self.base_time) * self.rate
                    error = samp - tag.offset


                    if round(error, 5):
                        duration_ms = 1000.0 * error / self.rate
                        print ("\nDETECTED OVERFLOW!  " + repr(round(error, 5)) + " samples \t(" + repr(round(duration_ms,5)) + " ms)  ",)
                        #print "\n\tTAG VAL " + repr(tag.value) + " received at " + repr(tag.offset) + " - sample " + repr(round(samp, 5)) + " ",

                        # update zero sample time so error does not accumulate
                        self.base_time = self.base_time + error / self.rate


        # if the rate was changed, save it...this shouldn't happen often
        for tag in tags:
            if pmt.equal(tag.key, pmt.intern('rx_rate')):
                oldrate = self.rate
                self.rate = pmt.to_python(tag.value)
                if (self.rate != oldrate) and tag.offset:
                    print ("\nDETECTED RATE CHANGE! - new rate is " + repr(self.rate) + " " + repr(oldrate),)

        # consume/produce everything
        return nitems
