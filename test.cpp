// Copyright 2020 Adam Tremblay

#include <iostream>
#include "MModel.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(constructor) {
    MModel mm("gagggagaggcgagaaa", 1);
    BOOST_REQUIRE(mm.freq("g") == 9);
    BOOST_REQUIRE(mm.freq("g", 'g') == 3);
    MModel mm2("gagggagaggcgagaaa", 0);
    BOOST_REQUIRE(mm2.freq("") == 17);
    BOOST_REQUIRE(mm2.freq("", 'g') == 9);
    BOOST_REQUIRE_THROW(mm.freq("abc"), std::runtime_error);
    BOOST_REQUIRE_THROW(mm.freq("abc", 'a'), std::runtime_error);
    BOOST_REQUIRE_THROW(mm.kRand("ewre"), std::runtime_error);
    MModel mm3("the cat went to the moon", 2);
    BOOST_REQUIRE(mm3.kRand("th") == 'e');
    BOOST_REQUIRE(mm3.freq("th", 'e') == 2);
    BOOST_REQUIRE(mm3.freq("th") == 2);
    BOOST_REQUIRE(mm3.kOrder() == 2);
    std::cout << mm3.generate("th", 10) << std::endl;
    std::cout << mm3.generate("ca", 40) << std::endl;
}
