#include "Configuration.h"

#include <fstream>


Configuration::Configuration(const std::string& _config_filename): config_filename(_config_filename) {
  std::ifstream config_read_file(config_filename);

  if (config_read_file.fail()) {
    // Criar arquivo padrão de configuração
    std::ofstream config_write_file(config_filename);

    config_write_file << "path=diary.md" << std::endl;
    config_write_file << "default_format=%d %t: %m" << std::endl;
  } else {
    // Arquivo de configuração existe
    // Ler coisas do arquivo
    std::string line;
    while(std::getline(config_read_file, line)) {
      std::string attribute_name;
      std::string attribute_value;

      attribute_name = line.substr(0, line.find("="));
      line.erase(0, line.find("=") + 1);

      attribute_value = line;

      configs[attribute_name] = attribute_value;
    }
  }
}

std::string Configuration::get_diary_filename() {
  return configs["path"];
}

std::string Configuration::get_format_messages() {
  return configs["default_format"];
}
