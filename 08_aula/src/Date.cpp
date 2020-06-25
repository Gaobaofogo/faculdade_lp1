#include "Date.h"

#include <sstream>

Date::Date(): day(0), month(0), year(0) {

}

std::string Date::to_string() {
  std::stringstream date;
  std::string date_to_return;

  date << day << "/" << month << "/" << year;
  date >> date_to_return;

  return date_to_return;
}

void Date::set_from_string(const std::string& date) {
  std::stringstream sdate(date);
  char discard;

  sdate >> day;
  sdate >> discard;
  sdate >> month;
  sdate >> discard;
  sdate >> year;
}
