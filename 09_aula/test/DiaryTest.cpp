#include "Diary.h"
#include "catch.h"

#include <string>


TEST_CASE("Atributos do diário", "[diario]") {
  Diary test_diary("fake_diary.md");
  std::string message = "Message 1";

  for (int i = 0; i < 51; ++i) {
    test_diary.insert_message(message);
  }

  REQUIRE( test_diary.messages_size == 51);
  REQUIRE( test_diary.messages_capacity == 80);
}

TEST_CASE("Diário usando o arquivo", "[diario]") {
  Diary test_diary("diary_test.md");
  Message m1;
  Date date;
  Time time;

  m1.content = "Mensagem 2";
  m1.date = date;
  m1.time = time;

  m1.date.set_from_string("26/06/2020");

  m1.time.set_from_string("03:03:03");


  REQUIRE( test_diary.messages_size == 1);
  REQUIRE( test_diary.messages_capacity == 10);

  test_diary.insert_message(m1);
  test_diary.insert_message(m1);
  test_diary.write();
}
