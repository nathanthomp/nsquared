//                       TOKEN.H                           //
// https://en.wikipedia.org/wiki/Lexical_analysis
// IDENTIFIER = Names assigned by the programmer                        
// KEYWORD = Reserved words of the language                             IF, WHILE, ELSE, RETURN
// SEPERATOR = Punctuation characters and paired delimiters             {, }, (, ), ; 
// OPERATOR = Symbols that operate on arguments and produce results     +, -, =
// LITERAL = Numeric, logical, textual, and reference literals          TRUE, 1234, 12.34, "string"
// COMMENT or WHITESPACE = Ignored characters
// MEMBERS: TYPE and optional VALUE

// token_init(type, value)
// token_init(type) value is default
// token_type_equals(Token_Type *this, Token_Type *that)

typedef enum {
    END_TOKEN = 0,
    UNSUPPORTED_TOKEN,
    SPACE_TOKEN,
    NUMBER_TOKEN,
    PLUS_TOKEN,
    MINUS_TOKEN,
    STAR_TOKEN,
    SLASH_TOKEN,
    LBRACK_TOKEN,
    RBRACK_TOKEN,
    LPAREN_TOKEN,
    RPAREN_TOKEN,
    LETTER_TOKEN
} Token_Type;       // TODO: Research typedef (token_t)

typedef struct {
    Token_Type type;
    char *text;
} Token;

//                       NEW                           //



// MEMBERS
// lexer_init()
//  updates content
// lexer_advance()
//  increments pos and updates current
// lexer_next_token()
//  returns a token struct and advances lexer
// lexer_char_error(char c)
//  prints message to stderr


//                       OLD                           //

typedef struct {
    size_t pos;
    char current;
    int line_number;
    const char* content; // Make global
} Lexer;

Token_Type lexer_peek(Lexer *lex) {
    if (lex->pos + 1 < strlen(lex->content)) {
        char next = lex->content[lex->pos + 1];
        if (isspace(next))
            return SPACE_TOKEN;
        else if (isdigit(next))
            return NUMBER_TOKEN;
        else if (isalpha(next))
            return LETTER_TOKEN;
        else
            return UNSUPPORTED_TOKEN;
    } else {
        return END_TOKEN;
    }
}

Token *lexer_next(Lexer *lex) {
    Token *tok = (Token*)malloc(sizeof(Token));
    if (lex->pos < strlen(lex->content)) {
        char current = lex->content[lex->pos];
        if (isspace(current)) {
            free(tok);
            lex->pos++;
            tok = lexer_next(lex);
}
