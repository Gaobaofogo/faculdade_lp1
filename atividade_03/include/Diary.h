#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>
#include <vector>

struct Diary {
  std::string filename;
  std::vector<Message> messages;

  Diary(const std::string& filename);
  void insert_message(const std::string& message);
  void insert_message(const Message& message);
  void write();
  std::vector<Message*> search(const std::string& text);
};

#endif
