# The NSquared Compiler

```
src/
          main.c
          lexer.c
          parser.c
          include/
                    token.h
                    lexer.h
                    parser.h
                    node.h
```

### How It Works
The NSquared compiler will be implemented with a lexer for lexical analysis, a parser for syntactic analysis, and a generator for target code creation.

## 1. Lexical Analysis
Starting with a string representing input, we tokenize the string to extract all the possible words and create tokens of them.

> var x = "Hello, World!"; -> 'var', 'x', '=', '"', 'Hello', ',', 'World', '!', '"', ';'

### Token
```c
/**
 * Token instance
 */
struct token {
          token_type type;            // type of token
          size_t start;               // start position of token
          size_t end;                 // end position of token

          struct token *next;         // linked list, next node
}

```

```c
enum token_type {
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

          // TODO
          ASSIGN_OP_TOKEN,        // =
          GREATER_THAN_OP_TOKEN,  // >
          LESS_THAN_OP_TOKEN,     // <
          //TODO

          // LITERAL
          INT_LIT_TOKEN,          // [0-9]+
          FLOAT_LIT_TOKEN,        // [0-9]+.[0-9]+
          BOOL_LIT_TOKEN,         // [true|false]
          CHAR_LIT_TOKEN,         // [a-zA-Z0-9]+

          // END
          END_TOKEN               // '\n'|EOF    
}
```

| Name | Description | Types |
| --- | --- | --- |
| IDENTIFIER | Names assigned by the programmer | |
| KEYWORD | Reserved words of the language | IF, ELSE, WHILE, RETURN, INT, FLOAT, STRING, CHAR, BOOL|
| SEPERATOR | Special characters for delimiters | {, }, (, ), ; |
| OPERATOR | Symbols that operate on arguments and produce resultsc| +, -, *, /, % |
| LITERAL | Numeric, logical, textual, and reference literals | TRUE, 1234, 12.34, "string", 'c' |
| COMMENT and WHITESPACE | Ignored characters | |


## 2. Syntactical Analysis

## Node

```c
typedef enum node_type {
          NUMBER,
          BINARY_OP,
          UNARY_OP
} node_type_t

typedef struct node {
          node_type_t type;
          union {
                    number_node node1
                    binary_op_node node2
                    unary_op_node node3
          }
} node_t
```


```
ast_node(ast_node_type_t type)
ast_node number_node(Token *number)
ast_node binary_operation_node(Token *left, Token *op, Token *right)
ast_node unary_operation_node(Token *op, Token *number) 
```

## Parser

```c
void parser_init() // "pass in tokens"
void parser_parse() // creates "program" node to begin parsing
void parser_advance() // updates current token
void parser_syntax_error(Token_Type expected, Token_Type actual) // prints message to stderr
```
```
expr      : term (PLUS|MINUS term)*
term      : factor (MULT|DIV factor)*
factor    : INT|FLOAT
          : PLUS|MINUS factor
          : LPAREN expr RPAREN

or

expr      : term (PLUS|MINUS term)*
          : KEYWORD IDENTIFIER EQUAL expr
term      : factor (MULT|DIV factor)*
factor    : PLUS|MINUS factor
          : power
power     : atom (POW factor)* // Shouldnt be atom (expr)??

atom      : LPAREN expr RPAREN
          : INT|FLOAT|IDENTIFIER
```

## Lexer
```c
void lexer_init() // updates content
token_t lexer_tokenize(const char *input)

          
void lexer_advance() // increments pos and updates current
void lexer_next_token() // returns a token struct and advances lexer
void lexer_char_error() // prints message to stderr
```

## Token
```c
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

          // TODO
          ASSIGN_OP_TOKEN,        // =
          GREATER_THAN_OP_TOKEN,  // >
          LESS_THAN_OP_TOKEN,     // <
          //TODO

          // LITERAL
          INT_LIT_TOKEN,          // [0-9]+
          FLOAT_LIT_TOKEN,        // [0-9]+.[0-9]+
          BOOL_LIT_TOKEN,         // [true|false]
          CHAR_LIT_TOKEN,         // [a-zA-Z0-9]+

          // END
          END_TOKEN               // '\n'|EOF    
}

typedef struct token {
          token_type_t type;
          char *value;
          size_t start;
          size_t end;
          size_t line;
          token_t *next;
} token_t;
```













--- 
Old
>
The lexer takes the input from the user and tokenizes it to create tokens that will represent the words of the NSquared language. The NSquared compiler lexer component is responsible for handling the input, and creating a singly linked list of tokens.

The parser then takes the singly linked list of tokens and creates an abstract syntax tree of nodes.


1. Take the input from user, pass the input to the parser
2. Take the parser, use the input and create a lexer with the input
3. Calling the parser_parse method will create an abstract syntax tree with the lexer

---

1. Take the input from user, use the lexer to create a singly linked list of token.
2. Take singly linked list of token, use the parser to create a tree of ast nodes.
3. Take tree of ast nodes, use the main method to determine if the tree represents a valid program.
4. If the tree does not represent a valid program, return error.
5. Take the tree of ast nodes, use the generator to create an assembly file. 
