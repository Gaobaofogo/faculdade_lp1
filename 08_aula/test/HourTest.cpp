#include "Hour.h"
#include "catch.h"


TEST_CASE("Hour", "[hour]") {
  Time time;
  time.set_from_string("13:59:30");

  REQUIRE( time.to_string() == "13:59:30" );
}
