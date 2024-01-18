#include <stdio.h>
#include <string.h>

#include "include/parser.h"

#define INPUT_SIZE 2048
#define MAX_ARGS 2

// REPL() (interpreter mode kinda like python's)
//  reads content from stdin
void REPL() {
    char input[INPUT_SIZE];
    while(1) {
        printf("ns>");
        fgets(input, sizeof(input), stdin);
        parser_t *par = parser_init(input);
        parser_parse(par);
        //lexer_t *lex = lexer_init(input);
        //printf("input: %s", lex->content);
    }
}

// slurp_file()
//  reads content from file
void slurp_file(const char *filename) {

}

// spit_file()
//  writes content to file

int main(int argc, char **argv) {
    if (argc != MAX_ARGS)
        // Not enough arguments
        return 1;
    else
        // Either second param is -r or a filename
        if (strcmp(argv[MAX_ARGS - 1], "-r") == 0)
            // REPL mode
            REPL();
        else
            // File mode
            slurp_file(argv[MAX_ARGS - 1]);
    
    return 0;
}
