#include "Diary.h"
#include "helper_time.h"

#include <fstream>
#include <sstream>
#include <string>

Diary::Diary(const std::string& _filename): filename(_filename), messages(nullptr) {
  messages_size = 0;
  messages_capacity = 10;
  messages = new Message[messages_capacity];

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

Diary::~Diary() {
  delete [] messages;
}

void Diary::insert_message(const std::string& message) {
  if (messages_capacity == messages_size) {
    messages_capacity *= 2;

    Message* new_messages = new Message[messages_capacity];
    
    for (size_t i = 0; i < messages_size; ++i) {
      new_messages[i] = messages[i];
    }

    Message* aux = messages;
    messages = new_messages;

    delete[] aux;
    new_messages = nullptr;
    aux = nullptr;
  }

  Message new_message;
  Date new_date;
  Time new_time;
  
  new_date.set_from_string(get_current_date());
  new_time.set_from_string(get_current_time());

  new_message.content = message;
  new_message.time = new_time;
  new_message.date = new_date;

  messages[messages_size] = new_message;
  ++messages_size;
}

void Diary::insert_message(const Message& message) {
  if (messages_capacity == messages_size) {
    messages_capacity *= 2;

    Message* new_messages = new Message[messages_capacity];
    
    for (size_t i = 0; i < messages_size; ++i) {
      new_messages[i] = messages[i];
    }

    Message* aux = messages;
    messages = new_messages;

    delete[] aux;
    new_messages = nullptr;
    aux = nullptr;
  }

  messages[messages_size] = message;
  ++messages_size;
}

void Diary::write() {
  if (messages_size == 0) {
    return;
  }

  std::ofstream write_file(filename);
  Date actual_date = messages[0].date;

  write_file << "# " << actual_date.to_string() << std::endl << std::endl;

  for (size_t i = 0; i < messages_size; ++i) {
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

Message* Diary::search(const std::string& text) {
  size_t position;

  for(size_t i = 0; i < messages_size; ++i) {
    position = messages[i].content.find(text);

    if (position != std::string::npos) {
      return &messages[i];
    }
  }

  return nullptr;
}
