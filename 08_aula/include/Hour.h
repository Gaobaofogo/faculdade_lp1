#ifndef TIME_H
#define TIME_H 

#include <ctime>
#include <string>

struct Time {
  unsigned second;
  unsigned minute;
  unsigned hour;

  Time();
  std::string get_time();
  void receive_current_time();
};

#endif
