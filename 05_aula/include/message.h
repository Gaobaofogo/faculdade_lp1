#ifndef MESSAGE_H
#define MESSAGE_H

#include "date.h"
#include "hour.h"

#include <string>

struct Message {
  Date date;
  Time time;
  std::string content;

  std::string format_to_file();
};

#endif
