#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define LEXER_IMPLEMENTATION
#include "include/lexer.h"

#define INPUT_SIZE 2048
#define MAX_ARGS 2

// REPL() (interpreter mode kinda like python's)
//  reads content from stdin
// slurp_file()
//  reads content from file
// spit_file()
//  writes content to file

int main(int argc, char **argv) {
    char input[INPUT_SIZE];

    if (argc != MAX_ARGS)
        // Not enough arguments
    else
        // Either second param is -r or a filename
        if (argv[MAX_ARGS - 1] = "-r")
            // REPL mode
        else
            // File mode 
    

    lexer_init(input);
    



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
    return 0;
}
