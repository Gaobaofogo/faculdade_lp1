#include "App.h"

#include <iostream>
#include <string>
#include <vector>

App::App(const std::string& filename, const std::string& _message_format) : diary(filename), message_format(_message_format) {
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

  } else if (operation == "list") {
    if (argc == 2) {
      list_messages();
    } else {
      list_messages(argv[2]);
    }

  } else if (operation == "search") {
    if (argc == 2) {
      search();
    } else {
      search(argv[2]);
    }

  } else if (operation == "interactive") {
    interactive();
  } else {
    return show_usage(argv[1]);
  }

  return 0;
}

void App::interactive() {
  std::cout << "Diário 1.0" << std::endl << std::endl;

  bool finish_program = false;
  char option;

  while (finish_program == false) {
    print_iteractive_options();

    std::cout << "Digite uma opção: ";
    std::cin >> option;

    if (option == '1') {
      std::cout << std::endl;
      list_messages();
      std::cout << std::endl;
    } else if (option == '2') {
      std::cout << std::endl;
      add_interactive();
      std::cout << std::endl;
    } else if (option == '0') {
      finish_program = true;
    } else {
      std::cout << "Opção desconhecida pelo programa" << std::endl << std::endl;
    }
  }
}

void App::add_interactive() {
  std::string message;

  std::cout << "Digite uma mensagem: ";
  std::getline(std::cin.ignore(), message);

  add(message);
}

void App::print_iteractive_options() {
  std::cout << "Selecione uma ação: " << std::endl << std::endl;
  std::cout << "1) Listar mensagens" << std::endl;
  std::cout << "2) Adicionar nova mensagem" << std::endl << std::endl;
  std::cout << "0) Finalizar" << std::endl << std::endl;
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

  std::cout << "Mensagem Adicionada" << std::endl;
}

void App::search() {
  std::string text;

  std::cout << "Digite o texto: ";
  std::getline(std::cin, text);

  search(text);
}

void App::search(const std::string& text) {
  std::vector<Message*> founded_messages = diary.search(text);

  if (founded_messages.size() == 0) {
    std::cout << "Mensagem com o termo dado não existe." << std::endl;
  } else {
    std::cout << founded_messages.size() << " mensagens encontradas:";
    std::cout << std::endl;

    for (auto it = founded_messages.begin(); it != founded_messages.end(); ++it) {
      std::cout << "- " << (*it)->content << std::endl;
    }
  }
}

int App::show_usage(char* prog_name) {
  std::cout << "Quantidade de argumentos inferior ao esperado." << std::endl;
  std::cout << "Ex.: " << prog_name << " add <mensagem>" << std::endl;

  return 1;
}

void App::list_messages() {
  for (auto it = diary.messages.begin(); it != diary.messages.end(); ++it) {
    std::cout << aux_list_messages("", (*it), message_format) << std::endl;
  }
}

void App::list_messages(const std::string& user_format) {
  for (auto it = diary.messages.begin(); it != diary.messages.end(); ++it) {
    std::cout << aux_list_messages("", (*it), user_format) << std::endl;
  }
}

std::string App::aux_list_messages(std::string final_message, Message message, std::string message_in_format) {
  std::string aux_final_message;
  bool encontrou_parametro = false;
  size_t position = message_in_format.find("%");

  if (position == std::string::npos) {
    return final_message;
  }

  aux_final_message.append(message_in_format.substr(0, message_in_format.find("%")));
  message_in_format.erase(0, message_in_format.find("%")); // Para compensar a porcentagem e o caracter. Ex.: %d tem tamanho 2

  if (message_in_format.size() && message_in_format.at(1) == 'm') {
    aux_final_message.append(message.content);
    encontrou_parametro = true;
  } else if (message_in_format.size() && message_in_format.at(1) == 'd') {
    aux_final_message.append(message.date.to_string());
    encontrou_parametro = true;
  } else if (message_in_format.size() && message_in_format.at(1) == 't') {
    aux_final_message.append(message.time.to_string());
    encontrou_parametro = true;
  }

  if (!encontrou_parametro) {
    aux_final_message.append(message_in_format.substr(0, 2));
  }

  message_in_format.erase(0, message_in_format.find("%") + 2); // Para compensar a porcentagem e o caracter. Ex.: %d tem tamanho 2

  final_message.append(aux_final_message);

  return aux_list_messages(final_message, message, message_in_format);
}
