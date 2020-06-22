#ifndef TIME_H
#define TIME_H 
#include <ctime>
#include <string>

struct Time {
  int second;
  int minute;
  int hour;

  std::string get_time();
  void receive_current_time();
};

#endif
