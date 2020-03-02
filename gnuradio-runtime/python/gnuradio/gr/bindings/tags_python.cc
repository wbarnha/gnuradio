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

#include <gnuradio/tags.h>

void bind_tags(py::module& m)
{
    using tag_t    = gr::tag_t;


    py::class_<tag_t,
        std::shared_ptr<tag_t>>(m, "tag_t")

        .def(py::init<>())
        .def(py::init<gr::tag_t const &>(),           py::arg("rhs") 
        )

        .def_static("offset_compare",&tag_t::offset_compare,
            py::arg("x"), 
            py::arg("y") 
        )

        .def_readwrite("offset", &tag_t::offset)
        .def_readwrite("key", &tag_t::key)
        .def_readwrite("value", &tag_t::value)
        .def_readwrite("srcid", &tag_t::srcid)
        .def_readwrite("marked_deleted", &tag_t::marked_deleted)

        // TODO - put in operators
        ;


} 
