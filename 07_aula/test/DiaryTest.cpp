#include "Diary.h"

#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
  Diary diary("diary.md");
  std::string message = "Message 1";

  for (int i = 0; i < 51; ++i) {
    diary.insert_message(message);
  }

  std::cout << diary.messages_size << std::endl;
  std::cout << diary.messages_capacity << std::endl;

  return 0;
}
