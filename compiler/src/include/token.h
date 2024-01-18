// token_init(type, value)
// token_init(type) value is default
// token_type_equals(Token_Type *this, Token_Type *that)

typedef enum token_type {

    // IDENTIFIER
    IDENTIFIER_TOKEN,       // [a-zA-Z]+

    // KEYWORD
    IF_KEY_TOKEN,           // if
    ELSE_KEY_TOKEN,         // else
    WHILE_KEY_TOKEN,        // while
    RETURN_KEY_TOKEN,       // return
    INT_KEY_TOKEN,          // int
    FLOAT_KEY_TOKEN,        // float
    BOOL_KEY_TOKEN,         // bool
    CHAR_KEY_TOKEN,         // char

    // SEPERATOR
    LPAREN_SEP_TOKEN,       // (
    RPAREN_SEP_TOKEN,       // )
    LBRACK_SEP_TOKEN,       // {
    RBRACK_SEP_TOKEN,       // }
    SEMI_SEP_TOKEN,         // ;

    // OPERATOR
    PLUS_OP_TOKEN,          // +
    MINUS_OP_TOKEN,         // -
    STAR_OP_TOKEN,          // *
    SLASH_OP_TOKEN,         // /
    MOD_OP_TOKEN,           // %

    // LITERAL
    INT_LIT_TOKEN,          // [0-9]+
    FLOAT_LIT_TOKEN,        // [0-9]+.[0-9]+
    BOOL_LIT_TOKEN,         // [true|false]
    CHAR_LIT_TOKEN,         // [a-zA-Z0-9]+

    // END
    END_TOKEN               // '\n'|EOF

} token_type_t;

typedef struct token {
    token_type_t type;
    char *value;
} token_t;

token_t *token_init();


