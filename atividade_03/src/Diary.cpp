#include "Diary.h"
#include "helper_time.h"

#include <fstream>
#include <sstream>
#include <string>

Diary::Diary(const std::string& _filename): filename(_filename) {
  std::ifstream read_file(filename);

  if (read_file.fail()) {
    return;
  }

  std::string line;
  std::string message;
  std::string time;
  std::string date;
  char discard;

  while (std::getline(read_file, line)) {
    std::stringstream sline(line);

    // Checar se a linha não é vazia garante que haverá como verificar o
    // primeiro caracter da string e evita erros na leitura de linhas vazias.
    if (line.length() && line.at(0) == '#') {
      sline >> discard;

      sline >> date;
    }

    if (line.length() && line.at(0) == '-') {
      // Compensa o traço e o espaço inicial
      sline >> discard;

      sline >> time;

      std::getline(sline, message);

      Message new_message;
      Date new_date;
      Time new_time;

      new_date.set_from_string(date);
      new_time.set_from_string(time);

      new_message.content = message;
      new_message.date = new_date;
      new_message.time = new_time;

      insert_message(new_message);
    }
  }

  read_file.close();
}

void Diary::insert_message(const std::string& message) {
  Message new_message;
  Date new_date;
  Time new_time;
  
  new_date.set_from_string(get_current_date());
  new_time.set_from_string(get_current_time());

  new_message.content = message;
  new_message.time = new_time;
  new_message.date = new_date;

  messages.push_back(new_message);
}

void Diary::insert_message(const Message& message) {
  messages.push_back(message);
}

void Diary::write() {
  if (messages.size() == 0) {
    return;
  }

  std::ofstream write_file(filename);
  Date actual_date = messages[0].date;

  write_file << "# " << actual_date.to_string() << std::endl << std::endl;

  for (size_t i = 0; i < messages.size(); ++i) {
    if (actual_date.to_string() != messages[i].date.to_string()) {
      actual_date = messages[i].date;

      write_file << std::endl;
      write_file << "# " << actual_date.to_string() << std::endl << std::endl;
    }

    write_file << "- " << messages[i].time.to_string();

    if (messages[i].content.length() && !(messages[i].content.at(0) == ' ')) {
      write_file << " ";
    }

    write_file << messages[i].content << std::endl;
  }

  write_file.close();
}

std::vector<Message*> Diary::search(const std::string& text) {
  std::vector<Message*> founded_messages;
  size_t position;

  for(auto it = messages.begin(); it != messages.end(); ++it) {
    position = it->content.find(text);

    if (position != std::string::npos) {
      founded_messages.push_back(&(*it));
    }
  }

  return founded_messages;
}
