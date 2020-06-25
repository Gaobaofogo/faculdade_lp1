#include "Hour.h"

#include <sstream>

Time::Time(): second(0), minute(0), hour(0) {

}

std::string Time::to_string() {
  std::stringstream time;
  std::string time_to_return;

  time << hour << ":" << minute << ":" << second;
  time >> time_to_return;

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
