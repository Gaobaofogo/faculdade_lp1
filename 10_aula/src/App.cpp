#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename) {
}

int App::run(int argc, char* argv[]) {
  if (argc == 1) {
    return show_usage(argv[0]);
  }

  std::string operation = argv[1];

  if (operation == "add") {
    if (argc == 2) {
      add();
    } else {
      add(argv[2]);
    }

    std::cout << "Mensagem Adicionada" << std::endl;
  } else if (operation == "list") {
    list_messages();
  } else if (operation == "search") {
    if (argc == 2) {
      search();
    } else {
      search(argv[2]);
    }
  } else {
    return show_usage(argv[1]);
  }

  return 0;
}

void App::add() {
  std::string message;

  std::cout << "Digite uma mensagem: ";
  std::getline(std::cin, message);

  add(message);
}

void App::add(const std::string& message) {
  diary.insert_message(message);
  diary.write();
}

void App::search() {
  std::string text;

  std::cout << "Digite o texto: ";
  std::getline(std::cin, text);

  search(text);
}

void App::search(const std::string& text) {
  Message* message = diary.search(text);

  if (message == nullptr) {
    std::cout << "Mensagem com o termo dado não existe." << std::endl;
  } else {
    std::cout << "Mensagem encontrada: " << message->content << std::endl;
  }
}

int App::show_usage(char* prog_name) {
  std::cout << "Quantidade de argumentos inferior ao esperado." << std::endl;
  std::cout << "Ex.: " << prog_name << " add <mensagem>" << std::endl;

  return 1;
}

void App::list_messages() {
  for (size_t i = 0; i < diary.messages_size; ++i) {
    const Message& message = diary.messages[i];
    std::cout << "-" << message.content << std::endl;
  }
}
