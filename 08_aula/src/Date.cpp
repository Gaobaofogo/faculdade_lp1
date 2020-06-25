#include "Date.h"

#include <sstream>

Date::Date(): day(0), month(0), year(0) {

}

std::string Date::get_date() {
  std::stringstream date;
  std::string date_to_return;

  date << day << "/" << month << "/" << year;
  date >> date_to_return;

  return date_to_return;
}

void Date::receive_current_date() {
  const std::string format = "%d/%m/%Y";
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(
      result,
      sizeof(result),
      format.c_str(),
      std::localtime(&time)
      );

  std::string date_string(result);
  std::stringstream sdate(date_string);
  char discard;

  sdate >> day;
  sdate >> discard;
  sdate >> month;
  sdate >> discard;
  sdate >> year;
}
