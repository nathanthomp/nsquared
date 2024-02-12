#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "include/parser.h"

#define INPUT_SIZE 2048

char *slurp_file(const char* filename);
void spit_file(const char* filename, char* content);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: nsc filename");
        return 1;
    }

    if (strcmp(argv[MAX_ARGS - 1], "-r") == 0) {
        char input[INPUT_SIZE];
        while (true) {
            printf("ns>");
            fgets(input, sizeof(input), stdin);
            for (struct token tok = lexer_tokenize(input); tok != NULL; tok = tok->next) {
                fprintf(stdout, "%d", tok->type);
            }
        }
    } else {
        slurp_file(argv[MAX_ARGS - 1]);
    }

    return 0;
}
