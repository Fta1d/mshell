#include "reader.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_BUFSIZE 1024

char *msh_read_line() {
    int c;
    int n = 0;
    int bufsize = DEFAULT_BUFSIZE;

    char *line = (char *)malloc(DEFAULT_BUFSIZE * sizeof(char));
    if (!line) {
        fprintf(stderr, "msh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            line[n] = '\0';
            return line;
        }

        line[n++] = c;

        if (n >= DEFAULT_BUFSIZE) {
            bufsize += DEFAULT_BUFSIZE;
            line = realloc(line, bufsize * sizeof(char));
            if (!line) {
                fprintf(stderr, "msh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}