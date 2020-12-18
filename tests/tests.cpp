#include <catch2/catch_all.hpp>

#include "rtc/vec.hpp"

using namespace Catch::literals;

TEST_CASE("Can be done specifying all coordinates", "[creating a vec struct]") {
    rtc::vec point{1.0f, 1.0f, 4.4f, 1.0f};

    REQUIRE(point.m_x == 1.0_a);
    REQUIRE(point.m_y == 1.0_a);
    REQUIRE(point.m_z == 4.4_a);
    REQUIRE(point.m_w == 1.0_a);
}

TEST_CASE("is created as point by default", "[creating a vec struct]") {
    rtc::vec defaut{2.43f, 3.12f, 4.21f};

    REQUIRE(defaut.m_w == 1.0_a);
    REQUIRE(defaut.is_point() == true);
}

TEST_CASE("when w coordinate is 0 then considered as vector", "[creating a vec struct]") {
    rtc::vec vector{1.0, 1.0, 1.0, 0.0};

    REQUIRE(vector.is_point() == false);
}

TEST_CASE("to create a point", "[helper functions]") {
    auto point = rtc::point(2.0, 4.0, 4.5);

    REQUIRE(point.is_point() == true);
}

TEST_CASE("to create a vector", "[helper functions]") {
    auto vector = rtc::vector(2.0, 4.0, 4.5);

    REQUIRE(vector.is_point() == false);
    REQUIRE(vector.m_w == 0.0f);
}

TEST_CASE("compairing two vec", "[helper functions]") {
    rtc::vec reference{2.4324, 321.413, 213.5466, 0.0};

    rtc::vec other_vec{2.4324, 321.413, 213.5466, 0.0};
    REQUIRE(reference == other_vec);
    REQUIRE(reference == reference);

    rtc::vec different{1.2, 1.2, 1.2};
    REQUIRE(reference != different);

    rtc::vec infinity{INFINITY, INFINITY, INFINITY};
    REQUIRE(reference != infinity);
}
