#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <string>

struct Date {
  unsigned day;
  unsigned month;
  unsigned year;

  Date();
  std::string to_string();
  bool compare_dates(Date& other_date);
  void set_from_string(const std::string& date);
};

#endif
