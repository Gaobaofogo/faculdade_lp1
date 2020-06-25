#include "Hour.h"

#include <iostream>


int main(int argc, char* argv[]) {
  Time time;

  time.receive_current_time();

  std::cout << time.get_time() << std::endl;

  return 0;
}
