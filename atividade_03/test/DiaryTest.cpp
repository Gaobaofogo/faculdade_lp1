#include "Diary.h"
#include "catch.h"

#include <string>
#include <fstream>
#include <iostream>


TEST_CASE("Atributos do diário", "[diario]") {
  Diary test_diary("fake_diary.md");
  std::string message = "Message 1";

  for (int i = 0; i < 51; ++i) {
    test_diary.insert_message(message);
  }

  REQUIRE( test_diary.messages.size() == 51);
  REQUIRE( test_diary.messages.capacity() == 64);
}

TEST_CASE("Diário usando o arquivo", "[diario]") {
  remove("diary_test.md");
  Diary test_diary("diary_test.md");
  Message m1;
  Date date;
  Time time;

  m1.content = "Mensagem 2";
  m1.date = date;
  m1.time = time;

  m1.date.set_from_string("26/06/2020");
  m1.time.set_from_string("03:03:03");

  test_diary.insert_message(m1);
  test_diary.write();

  std::ifstream test_file("diary_test.md");

  REQUIRE( test_diary.messages.size() == 1);
  REQUIRE( test_diary.messages.capacity() == 1);
  REQUIRE( test_file.good() == true );

  test_file.close();
  remove("diary_test.md");
}

TEST_CASE("Buscando mensagens no diário", "[diario]") {
  remove("diary_test.md");

  Diary test_diary("diary_test.md");
  std::string text_in_message = "1";
  std::string text_not_in_message = "2";
  Message m1;
  Date date;
  Time time;

  m1.content = "Mensagem 1";
  m1.date = date;
  m1.time = time;

  m1.date.set_from_string("26/06/2020");
  m1.time.set_from_string("03:03:03");

  test_diary.insert_message(m1);

  REQUIRE( test_diary.search(text_in_message).size() == 1 );
  REQUIRE( test_diary.search(text_in_message).capacity() == 1 );

  REQUIRE( test_diary.search(text_not_in_message).size() == 0 );
  REQUIRE( test_diary.search(text_not_in_message).capacity() == 0 );

  remove("diary_test.md");
}
