#ifdef _MSC_VER
#include <tchar.h>
#else
using TCHAR = char;
#endif
#include "build/configuration.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest/doctest.h>

#include "adl_scope.test.h"

int main(int /*argc*/, const TCHAR** /*argv*/) {
  doctest::Context dtc;
  auto             r = dtc.run();
  if (r != 0)
    return system("pause");
  return r;
}