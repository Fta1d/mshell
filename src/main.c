#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void msh_loop() {
    char *line;
    char **args;
    int8_t status;

    do {
        printf("> ");
        line = msh_read_line();
        args = msh_split_line(line);
        status = msh_execute(args);

        free(line);
        free(args);
    } while (status);
}

int main(int argc, char *argv[]) {
    // TODO: Load configuration files

    // Main shell loop
    msh_loop();

    // TODO: Execute termination routines

    return 0;
}

