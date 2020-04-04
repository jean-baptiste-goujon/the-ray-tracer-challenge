#define BOOST_TEST_MODULE test boost framework
#include <boost/test/included/unit_test.hpp>
#include "vec.hpp"

using namespace boost::test_tools;

auto EPSILON = tolerance(1e-6);

BOOST_AUTO_TEST_SUITE(creating_a_vec_struct)

BOOST_AUTO_TEST_CASE(can_be_done_specifying_all_coordinates){
    rtc::vec point{1.0, 1.0, 4.4, 1.0};

    BOOST_TEST_REQUIRE(point.m_x == 1.0, EPSILON);
    BOOST_TEST_REQUIRE(point.m_y == 1.0, EPSILON);
    BOOST_TEST_REQUIRE(point.m_z == 4.4, EPSILON);
    BOOST_TEST_REQUIRE(point.m_w == 1.0, EPSILON);
}

BOOST_AUTO_TEST_CASE(is_created_as_point_by_defautl){
    rtc::vec defaut{2.43, 3.12, 4.21};

    BOOST_TEST_REQUIRE(defaut.m_w == 1.0, EPSILON);
    BOOST_TEST_REQUIRE(defaut.is_point() == true);
}

BOOST_AUTO_TEST_CASE(when_w_coordinate_is_0_then_considered_as_vector){
    rtc::vec vector{1.0, 1.0, 1.0, 0.0};

    BOOST_TEST_REQUIRE(vector.is_point() == false);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(helper_functions)

BOOST_AUTO_TEST_CASE(to_create_a_point){
    auto point = rtc::point(2.0, 4.0, 4.5);

    BOOST_TEST_REQUIRE(point.is_point() == true);
}

BOOST_AUTO_TEST_CASE(to_create_a_vector){
    auto vector = rtc::vector(2.0, 4.0, 4.5);

    BOOST_TEST_REQUIRE(vector.is_point() == false);
    BOOST_TEST_REQUIRE(vector.m_w == 0.0);
}
BOOST_AUTO_TEST_SUITE_END()
