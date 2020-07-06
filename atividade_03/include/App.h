#ifndef APP_H
#define APP_H

#include "Diary.h"

#include <string>
#include <sstream>

struct App {
  Diary diary;
  std::string message_format;

  App(const std::string& filename, const std::string& _message_format);
  int run(int argc, char* argv[]);
  int show_usage(char* prog_name);
  void add();
  void add(const std::string& message);
  void search();
  void search(const std::string& text);
  void list_messages();
  void list_messages(const std::string& user_format);
  void interactive();
  void print_iteractive_options();
  void add_interactive();
  std::string format_string(std::string final_message, Message message, std::string message_in_format);
};

#endif
