#include "Hour.h"

#include <sstream>

Time::Time(): second(0), minute(0), hour(0) {

}

std::string Time::get_time() {
  std::stringstream time;
  std::string time_to_return;

  time << hour << ":" << minute << ":" << second;
  time >> time_to_return;

  return time_to_return;
}

void Time::receive_current_time() {
  const std::string format = "%H:%M:%S";
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(
      result,
      sizeof(result),
      format.c_str(),
      std::localtime(&time)
      );

  std::string time_string(result);
  std::stringstream stime(time_string);
  char discard;

  stime >> hour;
  stime >> discard;
  stime >> minute;
  stime >> discard;
  stime >> second;
}
