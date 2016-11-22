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


#ifndef INCLUDED_MISC_DEBUG_UTILS_CTRLPORT_MSG_BLOCK_H
#define INCLUDED_MISC_DEBUG_UTILS_CTRLPORT_MSG_BLOCK_H

#include <misc_debug_utils/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace misc_debug_utils {

    /*!
     * \brief <+description of block+>
     * \ingroup misc_debug_utils
     *
     */
    class MISC_DEBUG_UTILS_API ctrlport_msg_block : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<ctrlport_msg_block> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of misc_debug_utils::ctrlport_msg_block.
       *
       * To avoid accidental use of raw pointers, misc_debug_utils::ctrlport_msg_block's
       * constructor is in a private implementation
       * class. misc_debug_utils::ctrlport_msg_block::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace misc_debug_utils
} // namespace gr

#endif /* INCLUDED_MISC_DEBUG_UTILS_CTRLPORT_MSG_BLOCK_H */

