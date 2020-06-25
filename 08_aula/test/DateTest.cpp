#include "Date.h"
#include "catch.h"


TEST_CASE("Date", "[date]") {
  Date date;
  date.set_from_string("24/07/2020");

  REQUIRE( date.to_string() == "24/7/2020" );
}
