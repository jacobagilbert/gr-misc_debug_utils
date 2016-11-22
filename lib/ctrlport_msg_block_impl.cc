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
#include "ctrlport_msg_block_impl.h"

namespace gr {
  namespace misc_debug_utils {

    ctrlport_msg_block::sptr
    ctrlport_msg_block::make()
    {
      return gnuradio::get_initial_sptr
        (new ctrlport_msg_block_impl());
    }

    /*
     * The private constructor
     */
    ctrlport_msg_block_impl::ctrlport_msg_block_impl()
      : gr::block("ctrlport_msg_block",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(0, 0, 0))
    {
      message_port_register_out(pmt::mp("out"));
      message_port_register_in(pmt::mp("in"));
      set_msg_handler(pmt::mp("in"), boost::bind(&ctrlport_msg_block_impl::handle_msg, this, _1));
    }

    /*
     * Our virtual destructor.
     */
    ctrlport_msg_block_impl::~ctrlport_msg_block_impl()
    {
    }


    void
    ctrlport_msg_block_impl::setup_rpc()
    {
      std::cout << "\n~~~RPC SETUP WAS CALLED FOR MESSAGE BLOCK~~~\n" << std::endl;
    }


    void
    ctrlport_msg_block_impl::handle_msg(pmt::pmt_t msg)
    {
    }



  } /* namespace misc_debug_utils */
} /* namespace gr */

