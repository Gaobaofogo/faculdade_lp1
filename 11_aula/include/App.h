#ifndef APP_H
#define APP_H

#include "Diary.h"

#include <string>

struct App {
  Diary diary;

  App(const std::string& filename);
  int run(int argc, char* argv[]);
  int show_usage(char* prog_name);
  void add();
  void add(const std::string& message);
  void search();
  void search(const std::string& text);
  void list_messages();
};

#endif
