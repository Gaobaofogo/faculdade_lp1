#ifndef MESSAGE_H
#define MESSAGE_H

#include "Date.h"
#include "Hour.h"

#include <string>

struct Message {
  Date date;
  Time time;
  std::string content;

  std::string format_to_file();
};

#endif
