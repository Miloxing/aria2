/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2010 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef _D_BENCODE2_H_
#define _D_BENCODE2_H_

#include "common.h"

#include <string>
#include <iosfwd>

#include "ValueBase.h"

namespace aria2 {

namespace bencode2 {

const size_t MAX_STRUCTURE_DEPTH = 100;

SharedHandle<ValueBase> decode(std::istream& in);

// Decode the data in s.
SharedHandle<ValueBase> decode(const std::string& s);

// Decode the data in s. After decode is done successfully, return the
// bencoded string length in end.
SharedHandle<ValueBase> decode(const std::string& s, size_t& end);

SharedHandle<ValueBase> decode(const unsigned char* data, size_t length);

SharedHandle<ValueBase> decode
(const unsigned char* data, size_t length, size_t& end);

SharedHandle<ValueBase> decodeFromFile(const std::string& filename);

std::string encode(const ValueBase* vlb);

std::string encode(const SharedHandle<ValueBase>& vlb);

} // namespace bencode2

} // namespace aria2

#endif // _D_BENCODE2_H_
