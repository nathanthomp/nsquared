
// GLOBAL
// content

// STRUCT
// lexer {
//  pos
//  current
//  line_number
// }

// MEMBERS
// lexer_init()
//  updates content
// lexer_advance()
//  increments pos and updates current
// lexer_next_token()
//  returns a token struct and advances lexer
// lexer_char_error(char c)
//  prints message to stderr
#include <stdlib.h>
#include "token.h"

typedef struct lexer {
    const char *content;
    size_t content_size;
    size_t position;
    char current;
} lexer_t;

lexer_t *lexer_init(const char *input);

token_t *lexer_advance(lexer_t *lex);
