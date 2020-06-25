#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <string>

struct Date {
  unsigned day;
  unsigned month;
  unsigned year;

  Date();
  std::string get_date();
  bool compare_dates(Date& other_date);
  void receive_current_date();
};

#endif
