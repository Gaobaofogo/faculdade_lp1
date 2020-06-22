#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <string>

struct Date {
  int day;
  int month;
  int year;

  std::string get_date() {}
  bool compare_dates(Time& other_date) {}
  void receive_current_date();
};

// std::string format_current_date(const std::string& format);
// std::string get_current_date();
// std::string get_current_time();
// std::string extract_date(std::string line);
#endif
