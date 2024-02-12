#include "token.h"

typedef struct lexer {
    const char *content;
    size_t content_size;
    size_t position;
    char current;
} lexer_t;


void lexer_advance(int offset);
void lexer_tokenize(const char* content);
