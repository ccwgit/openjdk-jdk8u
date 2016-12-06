/*
 * Copyright (c) 1997, 2013, Oracle and/or its affiliates. All rights reserved.
 * Copyright 2012, 2014 SAP AG. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef CPU_PPC_VM_VM_VERSION_PPC_HPP
#define CPU_PPC_VM_VM_VERSION_PPC_HPP

#include "runtime/globals_extension.hpp"
#include "runtime/vm_version.hpp"

class VM_Version: public Abstract_VM_Version {
protected:
  enum Feature_Flag {
    fsqrt,
    fsqrts,
    isel,
    lxarxeh,
    cmpb,
    popcntb,
    popcntw,
    fcfids,
    vand,
    dcba,
    vcipher,
    vpmsumb,
    num_features // last entry to count features
  };
  enum Feature_Flag_Set {
    unknown_m             = 0,
    fsqrt_m               = (1 << fsqrt  ),
    fsqrts_m              = (1 << fsqrts ),
    isel_m                = (1 << isel   ),
    lxarxeh_m             = (1 << lxarxeh),
    cmpb_m                = (1 << cmpb   ),
    popcntb_m             = (1 << popcntb),
    popcntw_m             = (1 << popcntw),
    fcfids_m              = (1 << fcfids ),
    vand_m                = (1 << vand   ),
    dcba_m                = (1 << dcba   ),
    vcipher_m             = (1 << vcipher),
    vpmsumb_m             = (1 << vpmsumb),
    all_features_m        = -1
  };
  static int  _features;
  static int  _measured_cache_line_size;
  static const char* _features_str;
  static bool _is_determine_features_test_running;

  static void print_features();
  static void determine_features(); // also measures cache line size
  static void determine_section_size();
  static void power6_micro_bench();
public:
  // Initialization
  static void initialize();

  static bool is_determine_features_test_running() { return _is_determine_features_test_running; }
  // CPU instruction support
  static bool has_fsqrt()   { return (_features & fsqrt_m) != 0; }
  static bool has_fsqrts()  { return (_features & fsqrts_m) != 0; }
  static bool has_isel()    { return (_features & isel_m) != 0; }
  static bool has_lxarxeh() { return (_features & lxarxeh_m) !=0; }
  static bool has_cmpb()    { return (_features & cmpb_m) != 0; }
  static bool has_popcntb() { return (_features & popcntb_m) != 0; }
  static bool has_popcntw() { return (_features & popcntw_m) != 0; }
  static bool has_fcfids()  { return (_features & fcfids_m) != 0; }
  static bool has_vand()    { return (_features & vand_m) != 0; }
  static bool has_dcba()    { return (_features & dcba_m) != 0; }
  static bool has_vcipher() { return (_features & vcipher_m) != 0; }
  static bool has_vpmsumb() { return (_features & vpmsumb_m) != 0; }
  static bool has_mtfprd()  { return has_vcipher(); } // alias for P8
  static bool has_mtfprwa() { return has_vcipher(); } // alias for P8
  static bool has_mffprd()  { return has_vcipher(); } // alias for P8

  static const char* cpu_features() { return _features_str; }

  static int get_cache_line_size()  { return _measured_cache_line_size; }

  // Assembler testing
  static void allow_all();
  static void revert();
};

#endif // CPU_PPC_VM_VM_VERSION_PPC_HPP
