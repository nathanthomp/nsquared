# The NSquared Compiler
The NSquared compiler will be implemented with a lexer for tokenization (lexical analysis), a parser for creating an abstract syntax tree (syntactic analysis), and a generator that will traverse the abstract syntax tree and create assembly code.

1. Take the input from user, pass the input to the parser
2. Take the parser, use the input and create a lexer with the input
3. Calling the parser_parse method will create an abstract syntax tree with the lexer

---

1. Take the input from user, use the lexer to create a singly linked list of token.
2. Take singly linked list of token, use the parser to create a tree of ast nodes.
3. Take tree of ast nodes, use the main method to determine if the tree represents a valid program.
4. If the tree does not represent a valid program, return error.
5. Take the tree of ast nodes, use the generator to create an assembly file. 

## Abstract Syntax Tree

```c
typedef enum ast_node_type {

} ast_node_type_t

typedef struct ast_node {
          ast_node_type_t type;
          union {
                    number_node number_node
          }
} ast_node_t

ast_node(ast_node_type_t type)
ast_node number_node(Token *number)
ast_node binary_operation_node(Token *left, Token *op, Token *right)
ast_node unary_operation_node(Token *op, Token *number) 
```

## Parser

Structs:
```c
typedef struct {
          Token *current;
          ast_node *root;
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
void lexer_tokenize()
          
void lexer_advance() // increments pos and updates current
void lexer_next_token() // returns a token struct and advances lexer
void lexer_char_error() // prints message to stderr
```

## Token

Structs:
```c
typedef struct token {
          token_type_t type;
          char *value;
          size_t start;
          size_t end;
          token_t *next;
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

