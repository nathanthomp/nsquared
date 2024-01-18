#include <stdlib.h>
#include <stdio.h>
#include "include/parser.h"

parser_t *parser_init(const char *input) {
    parser_t *par = (parser_t*)malloc(sizeof(parser_t));
    par->lex = lexer_init(input);
    return par;
}

void parser_parse(parser_t *par) {
    while (par->lex->position < par->lex->content_size) {
        token_t *tok = lexer_advance(par->lex);
        printf("index: %d token:%d\n", par->lex->position, tok->type);
    }
}


// TODO:
//  For this input 
//      ns> hello
//
//  Make this output
//      index: 0 current: h token: 0
//      index: 1 current: e token: 0
//      index: 2 current: l token: 0
//      index: 3 current: l token: 0
//      index: 4 current: o token: 0
//      index: 5 current:  token: 23
