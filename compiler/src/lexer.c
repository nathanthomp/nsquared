#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/lexer.h"

lexer_t *lexer_init(const char *input) {
    lexer_t  *lex = (lexer_t*)malloc(sizeof(lexer_t)); // TODO: Deallocate
    lex->content = input;
    lex->content_size = strlen(input);
    lex->position = 0;
    lex->current = input[0]; // Could throw index out of bounds
    return lex;
}

token_t *lexer_advance(lexer_t *lex) {
    token_t *tok = token_init();
    if (lex->position < lex->content_size) {
        // Get the token
        tok->type = IDENTIFIER_TOKEN;
        // Update lexer
        lex->position++;
        lex->current = lex->content[lex->position];
    } else {
        // Get the eof token
        tok->type = END_TOKEN;
    }

    return tok;
}
