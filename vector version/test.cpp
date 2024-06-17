#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "functions.h"
#include "errorfinder.h"
#include "filegenerator.h"
#include "studentas.h"
#include "zmogus.h"

TEST_CASE("Default Constructor", "[Default Constructor]") {
    WARN("REQUIRE stops at [Default Constructor] failure:");
    studentas Studentas1;
    REQUIRE(Studentas1 == studentas());
}

TEST_CASE("Parameterized Constructor", "[Parameterized Constructor]") {
    WARN("REQUIRE stops at [Parameterized Constructor] failure:");
    studentas Studentas2("Test", "Test", {}, 0, 0.0);
    REQUIRE(Studentas2 == studentas("Test", "Test", {}, 0, 0.0));
}

TEST_CASE("Copy Constructor", "[Copy Constructor]") {
    WARN("REQUIRE stops at [Copy Constructor] failure:");
    studentas original("Test", "Test", {1, 2, 3}, 4, 5.0);
    studentas copy(original);
    REQUIRE(copy == original);
}

TEST_CASE("Move Constructor", "[Move Constructor]") {
    WARN("REQUIRE stops at [Move Constructor] failure:");
    studentas original("Test", "Test", {1, 2, 3}, 4, 5.0);
    studentas moved(std::move(original));
    REQUIRE(moved == studentas("Test", "Test", {1, 2, 3}, 4, 5.0));
}

TEST_CASE("Copy Assignment Operator", "[Copy Assignment Operator]") {
    WARN("REQUIRE stops at [Copy Assignment Operator] failure:");
    studentas original("Test", "Test", {1, 2, 3}, 4, 5.0);
    studentas copy;
    copy = original;
    REQUIRE(copy == original);
}

TEST_CASE("Move Assignment Operator", "[Move Assignment Operator]") {
    WARN("REQUIRE stops at [Move Assignment Operator] failure:");
    studentas original("Test", "Test", {1, 2, 3}, 4, 5.0);
    studentas moved;
    moved = std::move(original);
    REQUIRE(moved == studentas("Test", "Test", {1, 2, 3}, 4, 5.0));
}

