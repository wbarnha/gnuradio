/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/* This file is automatically generated using bindtool */

#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/endianness.h>

void bind_endianness(py::module& m)
{

    py::enum_<gr::endianness_t>(m,"endianness_t")
        .value("GR_MSB_FIRST", gr::GR_MSB_FIRST) // 0
        .value("GR_LSB_FIRST", gr::GR_LSB_FIRST) // 1
        .export_values()
    ;

} 
