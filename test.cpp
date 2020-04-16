// Copyright 2020 Adam Tremblay

#include <iostream>
#include "MModel.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(constructor) {
	MModel mm("gagggagaggcgagaaa", 0);
}