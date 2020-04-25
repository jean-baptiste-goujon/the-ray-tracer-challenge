#include <boost/test/unit_test.hpp>
#include "rtc/vec.hpp"


BOOST_AUTO_TEST_SUITE(vec_operations)
BOOST_AUTO_TEST_CASE(adding_vector_to_point_gives_new_point){
    rtc::vec start{3.0, 4.0, 5.0};
    rtc::vec vector{1.0, 2.0, 3.0, 0.0};

    rtc::vec expected_result{4.0, 6.0, 8.0, 1.0};
    BOOST_TEST_REQUIRE(start + vector == expected_result);
}

BOOST_AUTO_TEST_CASE(adding_two_vectors_gives_a_new_vector){
    rtc::vec first_vec{1.0, 2.0, 3.0, 0.0};
    rtc::vec second_vec{1.0, 2.0, 3.0, 0.0};

    BOOST_TEST_REQUIRE(first_vec+second_vec == rtc::vector(2.0, 4.0, 6.0));
}

BOOST_AUTO_TEST_CASE(substracting_two_points_gives_a_vector){
    rtc::vec first_point{1.0, 2.0, 3.0};
    rtc::vec second_point{1.0, 3.0, 4.0};

    BOOST_TEST_REQUIRE(second_point - first_point == rtc::vector(0.0, 1.0, 1.0));
}

BOOST_AUTO_TEST_CASE(substracting_a_vector_to_a_point_gives_a_point){
   rtc::vec point{1.0, 2.0, 3.0}; 
   rtc::vec movement=rtc::vector(2.0, 4.0, 6.0);

   BOOST_TEST_REQUIRE(point - movement == rtc::point(-1.0, -2.0, -3.0));
}

BOOST_AUTO_TEST_CASE(substracting_two_vectors_gives_a_vector){
    rtc::vec first_vector = rtc::vector(2.0, 4.0, 5.0);
    rtc::vec second_vector = rtc::vector(1.0, 3.0, 4.0);

    BOOST_TEST_REQUIRE(first_vector - second_vector == rtc::vector(1.0, 1.0, 1.0));
}

BOOST_AUTO_TEST_CASE(negating_a_vec_gives_its_opposite)
{
    rtc::vec point{2.0, 1.0, 0.2};

    auto expected_negated = rtc::vec{-2.0, -1.0, -0.2, -1.0};
    BOOST_TEST_REQUIRE(-point == expected_negated);
}

BOOST_AUTO_TEST_CASE(vec_supports_scalar_product)
{
    auto point = rtc::point(1.2, 2.3, 2.3);
    auto expected_result = rtc::vec{2.4, 4.6, 4.6, 2.0};
    BOOST_TEST_REQUIRE(point * 2 == expected_result);

    expected_result = rtc::vec{0.6, 1.15, 1.15, 0.5};
    BOOST_TEST_REQUIRE(point * 0.5 == expected_result);
}

BOOST_AUTO_TEST_CASE(vec_supports_scalar_division)
{
    auto point = rtc::point(1.2, 2.3, 2.3);
    auto expected_result = rtc::vec{0.6, 1.15, 1.15, 0.5};
    
    BOOST_TEST_REQUIRE(point / 2 == expected_result);
}

BOOST_AUTO_TEST_SUITE_END()
