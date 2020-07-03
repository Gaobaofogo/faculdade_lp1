#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <map>
#include <string>


struct Configuration {
  std::string config_filename;
  std::map<std::string, std::string> configs;

  Configuration(const std::string& _config_filename);
  std::string get_diary_filename();
  std::string get_format_messages();
};
#endif
