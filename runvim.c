#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <sys/syslimits.h>
#include <unistd.h>

#define TOOL_PATH "/usr/local/bin"

int main(int argc, char **argv) {
  char *executable_name = basename(argv[0]);
  char full_executable[ARG_MAX];
  snprintf(full_executable, ARG_MAX, "%s/%s", TOOL_PATH, executable_name);

  char **new_argv = (char **) malloc (sizeof(char*) * (argc+1));
  new_argv[0] = "/bin/sh";
  new_argv[1] = full_executable;
  for (int i=1; i<argc; i++) {
    new_argv[i+1] = argv[i];
  }

  if (execv("/bin/sh", new_argv)) {
    perror(argv[0]);
    return 1;
  }
}

