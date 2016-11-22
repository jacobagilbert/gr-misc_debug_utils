/* -*- c++ -*- */

#define MISC_DEBUG_UTILS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "misc_debug_utils_swig_doc.i"

%{
#include "misc_debug_utils/ctrlport_msg_block.h"
#include "misc_debug_utils/ctrlport_msg_stream.h"
%}


%include "misc_debug_utils/ctrlport_msg_block.h"
GR_SWIG_BLOCK_MAGIC2(misc_debug_utils, ctrlport_msg_block);
%include "misc_debug_utils/ctrlport_msg_stream.h"
GR_SWIG_BLOCK_MAGIC2(misc_debug_utils, ctrlport_msg_stream);
