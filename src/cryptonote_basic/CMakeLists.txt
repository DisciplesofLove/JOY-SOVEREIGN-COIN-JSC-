# Copyright (c) 2014-2024, The Monero Project
#
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are
# permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this list of
#    conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice, this list
#    of conditions and the following disclaimer in the documentation and/or other
#    materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its contributors may be
#    used to endorse or promote products derived from this software without specific
#    prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
# THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
# THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

if(APPLE)
  if(DEPENDS)
    list(APPEND EXTRA_LIBRARIES "-framework Foundation -framework ApplicationServices -framework AppKit -framework IOKit")
  else()
    find_library(IOKIT_LIBRARY IOKit)
    mark_as_advanced(IOKIT_LIBRARY)
    list(APPEND EXTRA_LIBRARIES ${IOKIT_LIBRARY})
  endif()
endif()

monero_add_library(cryptonote_format_utils_basic
  cryptonote_format_utils_basic.cpp
)
target_link_libraries(cryptonote_format_utils_basic
  PUBLIC
  cncrypto
)

set(cryptonote_basic_sources
  account.cpp
  connection_context.cpp
  cryptonote_basic_impl.cpp
  cryptonote_format_utils.cpp
  difficulty.cpp
  proof_of_inference.cpp
  hardfork.cpp
  merge_mining.cpp
  miner.cpp)

set(cryptonote_basic_headers)

monero_find_all_headers(cryptonote_basic_private_headers "${CMAKE_CURRENT_SOURCE_DIR}")

monero_private_headers(cryptonote_basic
  ${cryptonote_basic_private_headers})
monero_add_library(cryptonote_basic
  ${cryptonote_basic_sources}
  ${cryptonote_basic_headers}
  ${cryptonote_basic_private_headers})
target_link_libraries(cryptonote_basic
  PUBLIC
    common
    cncrypto
    checkpoints
    cryptonote_format_utils_basic
    device
    ${Boost_DATE_TIME_LIBRARY}
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    ${Boost_SERIALIZATION_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_THREAD_LIBRARY}
  PRIVATE
    ${EXTRA_LIBRARIES})
