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

} Token_Type;       // TODO: Research typedef (token_t)

typedef struct {
    Token_Type type;
    char *text;
} Token;
