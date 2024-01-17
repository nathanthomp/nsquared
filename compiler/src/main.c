#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "include/lexer.h"

#define INPUT_SIZE 2048
#define MAX_ARGS 2

// REPL() (interpreter mode kinda like python's)
//  reads content from stdin
void REPL() {

}

// slurp_file()
//  reads content from file
void slurp_file(const char *filename) {

}

// spit_file()
//  writes content to file

int main(int argc, char **argv) {
    char input[INPUT_SIZE];

    if (argc != MAX_ARGS)
        // Not enough arguments
        return 1;
    else
        // Either second param is -r or a filename
        if (argv[MAX_ARGS - 1] == "-r")
            // REPL mode
            REPL();
        else
            // File mode
            slurp_file(argv[MAX_ARGS - 1]);
    

    lexer_init();
    return 0;



    /* OLD

    // Get the input
	char input[INPUT_BUFF_SIZE] = (char *)malloc(sizeof(char) * INPUT_BUFF_SIZE);

    // Read evaluate print loop (REPL)
    //  read in string as input, terminated by nextline char
    //  send that input to the lexer, which will find each token in the input
    //  print out each token foun in the input
    while (1) {
        printf("ns> ");
        fgets(input, INPUT_BUFF_SIZE, stdin);
        Lexer *lex = lexer_init(input);
        Token *tok = lexer_next(lex);
        printf("Token:%s\tType:%d\n", tok->text, tok->type);
        while (tok->type != END_TOKEN) {
            tok = lexer_next(lex);
            printf("Token:%s\tType:%d\n", tok->text, tok->type);
        }
    }

    free(input);

    */
}
