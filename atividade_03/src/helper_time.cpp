#include "helper_time.h"

// As 3 funções abaixo eu peguei diretamente do pdf da atividade
std::string format_current_date(const std::string& format) {
  std::time_t time = std::time(nullptr);
  char result[1024];
  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() {
  return format_current_date("%d/%m/%Y");
}

std::string get_current_time() {
  return format_current_date("%H:%M:%S");
}

// Tirei a lógica de como fatiar uma string do link abaixo:
// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::string extract_date(std::string line) {
  line.erase(0, line.find(" ") + 1);

  return line;
}
