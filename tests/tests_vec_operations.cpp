#include <catch2/catch_all.hpp>

#include "rtc/vec.hpp"
#include <cmath>

TEST_CASE("Adding vector to point gives new point", "[vec operations]") {
  rtc::vec start{3.0, 4.0, 5.0};
  rtc::vec vector{1.0, 2.0, 3.0, 0.0};

  rtc::vec expected_result{4.0, 6.0, 8.0, 1.0};
  REQUIRE(start + vector == expected_result);
}

TEST_CASE("Adding two vectors gives new vector", "[vec operations]") {
  rtc::vec first_vec{1.0, 2.0, 3.0, 0.0};
  rtc::vec second_vec{1.0, 2.0, 3.0, 0.0};

  REQUIRE(first_vec+second_vec == rtc::vector(2.0, 4.0, 6.0));
}

TEST_CASE("Substracting two points gives a vector", "[vec operations]") {
  rtc::vec first_point{1.0, 2.0, 3.0};
  rtc::vec second_point{1.0, 3.0, 4.0};

  REQUIRE(second_point - first_point == rtc::vector(0.0, 1.0, 1.0));
}

TEST_CASE("Substracting a vector to a point gives a point", "[vec operations]") {
  rtc::vec first_point{1.0, 2.0, 3.0};
  rtc::vec second_point{1.0, 3.0, 4.0};

  REQUIRE(second_point - first_point == rtc::vector(0.0, 1.0, 1.0));
}

TEST_CASE("Substracting two vectors gives a vector", "[vec operations]") {
  rtc::vec first_vector = rtc::vector(2.0, 4.0, 5.0);
  rtc::vec second_vector = rtc::vector(1.0, 3.0, 4.0);

  REQUIRE(first_vector - second_vector == rtc::vector(1.0, 1.0, 1.0));
}

TEST_CASE("Negating a vec gives its opposite", "[vec operations]") {
  rtc::vec point{2.0, 1.0, 0.2};

  auto expected_negated = rtc::vec{-2.0, -1.0, -0.2, -1.0};
  REQUIRE(-point == expected_negated);
}

TEST_CASE("vec supports scalar products", "[vec operations]") {
  auto point = rtc::point(1.2, 2.3, 2.3);
  auto expected_result = rtc::vec{2.4, 4.6, 4.6, 2.0};
  REQUIRE(point * 2 == expected_result);

  expected_result = rtc::vec{0.6, 1.15, 1.15, 0.5};
  REQUIRE(point * 0.5 == expected_result);
}

TEST_CASE("vec supports scalar division", "[vec operations]") {
  auto point = rtc::point(1.2, 2.3, 2.3);
  auto expected_result = rtc::vec{0.6, 1.15, 1.15, 0.5};
  
  REQUIRE(point / 2 == expected_result);
}

TEST_CASE("The magnitude of a unit vector is 1", "[vec operations]") {
  auto unit_vec = rtc::vector(1.0, 0.0, 0.0);
  REQUIRE(unit_vec.magnitude() == 1.0);

  unit_vec = rtc::vector(0.0, 1.0, 0.0);
  REQUIRE(unit_vec.magnitude() == 1.0);

  unit_vec = rtc::vector(0.0, 0.0, 1.0);
  REQUIRE(unit_vec.magnitude() == 1.0);
}

TEST_CASE("The magnitude of a vector uses Pythagoras' theorem", "[vec operations]") {
  double expected_magnitude = std::sqrt(14.0);

  auto vector = rtc::vector(1.0, 2.0, 3.0);
  REQUIRE(vector.magnitude() == Catch::Approx(expected_magnitude));

  auto inverse_vector = rtc::vector(-1.0, -2.0, -3.0);
  REQUIRE(vector.magnitude() == Catch::Approx(expected_magnitude));
}
