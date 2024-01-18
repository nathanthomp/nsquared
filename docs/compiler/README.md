# The NSquared Compiler

## Parser

Nodes:
```c
NUMBER(Token *number)
BINARY_OPERATION(Token *left, Token *op, Token *right)
UNARY_OPERATION(Token *op, Token *number) 
```
Structs:
```c
typedef struct {
          Token *current;
} Parser;
```
Members:
```c
void parser_init() // "pass in tokens"
void parser_parse() // creates "program" node to begin parsing
void parser_advance() // updates current token
void parser_syntax_error(Token_Type expected, Token_Type actual) // prints message to stderr
```
Grammar:
```
expr      : term (PLUS|MINUS term)*
term      : factor (MULT|DIV factor)*
factor    : INT|FLOAT
          : PLUS|MINUS factor
          : LPAREN expr RPAREN
```

## Lexer

Structs:
```c
typedef struct lexer {
          Token *current;
} lexer_t;
```
Members:
```c
void lexer_init() // updates content
void lexer_advance() // increments pos and updates current
void lexer_next_token() // returns a token struct and advances lexer
void lexer_char_error() // prints message to stderr
```

## Token

Structs:
```c
typedef enum token_type {
          
} token_type_t;

typedef struct token {
          token_type_t type;
          char *value;
} token_t;
```
Members:
```c
token_t *token_init(token_type_t type, char *value)
token_t *token_init(token_type_t type)
_Bool token_is_match(token_type_t this, token_type_t that)
```

| Name | Description | Examples |
| --- | --- | --- |
| IDENTIFIER | Names assigned by the programmer | |
| KEYWORD | Reserved words of the language | IF, ELSE, WHILE, RETURN, INT, FLOAT, STRING, CHAR, BOOL|
| SEPERATOR | Special characters for delimiters | {, }, (, ), ; |
| OPERATOR | Symbols that operate on arguments and produce results| +, -, *, /, % |
| LITERAL | Numeric, logical, textual, and reference literals | TRUE, 1234, 12.34, "string", 'c' |
| COMMENT and WHITESPACE | Ignored characters | |

