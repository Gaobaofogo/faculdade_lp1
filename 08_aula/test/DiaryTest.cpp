#include "Diary.h"
#include "catch.h"

#include <string>

Diary diary_test_factory() {
  Diary diary("diary.md");
  std::string message = "Message 1";

  for (int i = 0; i < 51; ++i) {
    diary.insert_message(message);
  }

  return diary;
}

TEST_CASE("Diário", "[diario]") {
  Diary test_diary = diary_test_factory();

  REQUIRE( test_diary.messages_size == 51);
  REQUIRE( test_diary.messages_capacity == 60);
}
