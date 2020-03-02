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

#include <gnuradio/fxpt.h>

void bind_fxpt(py::module& m)
{
    using fxpt    = gr::fxpt;


    py::class_<fxpt,
        std::shared_ptr<fxpt>>(m, "fxpt")

        .def(py::init<>())
        .def(py::init<gr::fxpt const &>(),           py::arg("arg0") 
        )

        .def_static("float_to_fixed",&fxpt::float_to_fixed,
            py::arg("x") 
        )
        .def_static("fixed_to_float",&fxpt::fixed_to_float,
            py::arg("x") 
        )
        .def_static("sin",&fxpt::sin,
            py::arg("x") 
        )
        .def_static("cos",&fxpt::cos,
            py::arg("x") 
        )
        .def_static("sincos",&fxpt::sincos,
            py::arg("x"), 
            py::arg("s"), 
            py::arg("c") 
        )
        ;


} 
