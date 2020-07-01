#ifndef TIME_H
#define TIME_H 

#include <ctime>
#include <string>

struct Time {
  unsigned second;
  unsigned minute;
  unsigned hour;

  Time();
  void set_from_string(const std::string& time);
  std::string to_string();
};

#endif
