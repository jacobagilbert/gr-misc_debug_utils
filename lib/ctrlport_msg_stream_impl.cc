/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "ctrlport_msg_stream_impl.h"

namespace gr {
  namespace misc_debug_utils {

    ctrlport_msg_stream::sptr
    ctrlport_msg_stream::make()
    {
      return gnuradio::get_initial_sptr
        (new ctrlport_msg_stream_impl());
    }

    /*
     * The private constructor
     */
    ctrlport_msg_stream_impl::ctrlport_msg_stream_impl()
      : gr::sync_block("ctrlport_msg_stream",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(0, 0, 0))
    {
      message_port_register_out(pmt::mp("out"));
      message_port_register_in(pmt::mp("in"));
      set_msg_handler(pmt::mp("in"), boost::bind(&ctrlport_msg_stream_impl::handle_msg, this, _1));
    }


    void
    ctrlport_msg_stream_impl::setup_rpc()
    {
      std::cout << "\n~~~RPC SETUP WAS CALLED FOR MESSAGE + STREAM BLOCK~~~\n" << std::endl;
    }


    void
    ctrlport_msg_stream_impl::handle_msg(pmt::pmt_t msg)
    {
    }


    /*
     * Our virtual destructor.
     */
    ctrlport_msg_stream_impl::~ctrlport_msg_stream_impl()
    {
    }

    int
    ctrlport_msg_stream_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace misc_debug_utils */
} /* namespace gr */

