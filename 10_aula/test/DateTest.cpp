#include "Date.h"
#include "catch.h"


TEST_CASE("Date", "[date]") {
  Date date1;
  Date date2;
  Date date3;
  Date date4;
  date1.set_from_string("24/07/2020");
  date2.set_from_string("26/06/2020");
  date3.set_from_string(" 26/06/2020");
  date4.set_from_string("26/06/2020:");

  REQUIRE( date1.to_string() == "24/07/2020" );
  REQUIRE( date2.to_string() == "26/06/2020" );
  REQUIRE( date3.to_string() == "26/06/2020" );
  REQUIRE( date4.to_string() == "26/06/2020" );
}
