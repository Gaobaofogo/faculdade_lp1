#include "Hour.h"

#include <sstream>

Time::Time(): second(0), minute(0), hour(0) {

}

std::string Time::to_string() {
  std::stringstream stime;
  std::string time_to_return;

  if (hour < 10) {
    stime << 0;
  }

  stime << hour << ":";

  if (minute < 10) {
    stime << 0;
  }

  stime << minute << ":";

  if (second < 10) {
    stime << 0;
  }

  stime << second;
  stime >> time_to_return;

  return time_to_return;
}

void Time::set_from_string(const std::string& time) {
  std::stringstream stime(time);
  char discard;

  stime >> hour;
  stime >> discard;
  stime >> minute;
  stime >> discard;
  stime >> second;
}
