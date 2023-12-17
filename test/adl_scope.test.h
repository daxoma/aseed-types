#pragma once

#include <doctest/doctest/doctest.h>
#include "../adl_scope.h"

TEST_CASE("adl_scope") {
  using namespace aseed;
  struct tag1 {};
  using scope1 = types::adl_scope<tag1>;

  struct tag2 {};
  using scope2 = types::adl_scope<tag2>;

  SUBCASE("scope1") {
    static_assert(0 == scope1::index<char>());
    static_assert(1 == scope1::index<short>());
    static_assert(2 == scope1::index<int>());
    static_assert(1 == scope1::index<short>());
  }

  SUBCASE("scope2") {
    static_assert(0 == scope2::index<int>());
    static_assert(1 == scope2::index<short>());
    static_assert(2 == scope2::index<char>());
    static_assert(1 == scope2::index<short>());
  }
}
