
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

void lexer_init();
