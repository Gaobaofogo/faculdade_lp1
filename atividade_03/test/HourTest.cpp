#include "Hour.h"
#include "catch.h"


TEST_CASE("Hour", "[hour]") {
  Time time;
  time.set_from_string("02:59:00");

  REQUIRE( time.to_string() == "02:59:00" );
}
