#include "Date.h"

#include <iostream>


int main(int argc, char* argv[]) {
  Date date;

  date.receive_current_date();

  std::cout << date.get_date() << std::endl;

  return 0;
}
