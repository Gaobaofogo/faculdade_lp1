#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>

struct Diary {
  std::string filename;
  Message* messages;
  size_t messages_size;
  size_t messages_capacity;

  Diary(const std::string& filename);
  ~Diary();
  void insert_message(const std::string& message);
  void write();
};

#endif
