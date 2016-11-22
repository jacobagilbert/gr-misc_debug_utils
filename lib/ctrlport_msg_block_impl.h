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

#ifndef INCLUDED_MISC_DEBUG_UTILS_CTRLPORT_MSG_BLOCK_IMPL_H
#define INCLUDED_MISC_DEBUG_UTILS_CTRLPORT_MSG_BLOCK_IMPL_H

#include <misc_debug_utils/ctrlport_msg_block.h>

namespace gr {
  namespace misc_debug_utils {

    class ctrlport_msg_block_impl : public ctrlport_msg_block
    {
     private:
      // Nothing to declare in this block.

     public:
      ctrlport_msg_block_impl();
      ~ctrlport_msg_block_impl();
      void setup_rpc();

      void handle_msg(pmt::pmt_t);

    };

  } // namespace misc_debug_utils
} // namespace gr

#endif /* INCLUDED_MISC_DEBUG_UTILS_CTRLPORT_MSG_BLOCK_IMPL_H */

