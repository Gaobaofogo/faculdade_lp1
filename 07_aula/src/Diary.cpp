#include "Diary.h"

#include <string>

Diary::Diary(const std::string& _filename): filename(_filename), messages(nullptr) {
  messages_size = 0;
  messages_capacity = 10;
  messages = new Message[messages_capacity];
}

Diary::~Diary() {
  delete [] messages;
}

void Diary::insert_message(const std::string& message) {
  if (messages_capacity == messages_size) {
    messages_capacity += 10;

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
  new_message.content = message;

  messages[messages_size] = new_message;
  ++messages_size;
}

void Diary::write() {

}
