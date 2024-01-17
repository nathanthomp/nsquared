// GRAMMAR
//  expr    : term (PLUS|MINUS term)*
//  term    : factor (MUL/DIV factor)*
//  factor  : INT|FLOAT
//          : PLUS|MINUS factor
//          : LPAREN expr RPAREN

// NODES
// NUMBER(Token *number)
// BINARY_OPERATION(Token *left_number, Token op, Token *right_number)
// UNARY_OPERATION(Token *op, Token *number)

// STRUCT
// Parser
//  Token *current
//      the current token

// MEMBERS
// parser_init()
//  "pass in tokens"
// parser_parse()
//  creates "program node"
// parser_advance()
//  updates current
// parser_syntax_error(Token_Type expected, Token_Type actual)
//  prints message to stderr
