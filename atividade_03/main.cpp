#include "App.h"
#include "Configuration.h"

int main(int argc, char* argv[]) {
  Configuration configuration("diary.config");
  App aplicativo(
      configuration.get_diary_filename(),
      configuration.get_format_messages()
      );

  return aplicativo.run(argc, argv);
}
