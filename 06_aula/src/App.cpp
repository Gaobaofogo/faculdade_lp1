#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename) {
}

int App::run(int argc, char* argv[]) {
  if (argc == 1) {
    return show_usage();
  }

  std::string operation = argv[1];

  if (operation == "add") {
    if (argc == 2) {
      add();
    } else {
      add(argv[2]);
    }
  } else if (operation == "list") {
    list_messages();
  } else {
    return show_usage();
  }

  return 0;
}

void App::add() {
  std::string message;

  std::cout << "Digite uma mensagem: ";
  std::getline(std::cin, message);

  add(message);
}

void App::add(const std::string message) {
  diary.insert_message(message);
  diary.write();
}

int App::show_usage() {
  return 1;
}

void App::list_messages() {
  for (size_t i = 0; i < diary.messages_size; ++i) {
    const Message& message = diary.messages[i];
    std::cout << "-" << message.content << std::endl;
  }
}
