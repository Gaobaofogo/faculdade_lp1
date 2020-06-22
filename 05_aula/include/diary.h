#ifndef DIARY_H
#define DIARY_H

#include <string>

struct Diary {
  std::string file_name;

  bool insert_message(std::string message);
  void list_messages();
};

#endif
