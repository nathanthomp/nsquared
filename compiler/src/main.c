#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define INPUT_BUFF_SIZE 2048
#define TOKEN_BUFF_SIZE 256

typedef enum {
    END_TOKEN = 0,
    NEWLINE_TOKEN,
    UNKNOWN_TOKEN,
    UNSUPPORTED_TOKEN,
    NUMBER_TOKEN,
    SPACE_TOKEN,
    BLANK_TOKEN,
    LETTER_TOKEN,
    PLUS_TOKEN,
    MINUS_TOKEN,
    STAR_TOKEN,
    SLASH_TOKEN,
    LBRACK_TOKEN,
    RBRACK_TOKEN,
    LPAREN_TOKEN,
    RPAREN_TOKEN
} Token_Type;

typedef struct {
    Token_Type type;
    char *text;
} Token;

/*
Token *next_token(int *pos, const char *input) {
	
	// To print the pointer: *pos
	// To increment the pointer: (*pos)++;
	// printf("pos = %d\n", *pos);
	// printf("strlen(input) = %ld\n", strlen(input));

	// Number
	// Operator
 
	Token *tok = (Token*)malloc(sizeof(Token));
	char current = input[*pos];
	tok-> text = current;

	if (isdigit(current)) {
		tok->type = NUMBER_TOKEN;
	} else if (isalpha(current)) { 
		switch (current) {
			case '+': tok->type = PLUS_TOKEN; break;
			case '-': tok->type = MINUS_TOKEN; break;
			case '*': tok->type = STAR_TOKEN; break;
			case '/': tok->type = SLASH_TOKEN; break;
			case '{': tok->type = LBRACK_TOKEN; break;
			case '}': tok->type = RBRACK_TOKEN; break;
			case '(': tok->type = LPAREN_TOKEN; break;
			case ')': tok->type = RPAREN_TOKEN; break;
			default: tok->type = LETTER_TOKEN; break;
		}
	} else {
		tok->type = UNKNOWN_TOKEN;
	}

	(*pos)++;
	return tok;
}
*/

typedef struct {
    size_t pos;
    const char* content;
} Lexer;

Token *lexer_next(Lexer *lex);

Token_Type lexer_peek(Lexer *lex) {
    return lexer_next(lex)->type;
}

Token *lexer_next(Lexer *lex) {
    Token *tok = (Token*)malloc(sizeof(Token));
    if (lex->pos < strlen(lex->content)) {
        char current = lex->content[lex->pos];
        if (isspace(current)) {
            free(tok);
            lex->pos++;
            tok = lexer_next(lex);
        } else if (isdigit(current)) {
            while (lexer_peek(lex) == TOKEN_NUMBER) {
            
            }
            tok->type = NUMBER_TOKEN;
            tok->text = "NUMBER";
        } else if (isalpha(current)) {
            tok->type = LETTER_TOKEN;
            tok->text = "LETTER"; // Will have to convert char to str
        } else {
            tok->type = UNSUPPORTED_TOKEN;
            tok->text = "UNSUPPORTED";
        }
        lex->pos++;
    } else {
        tok->type = END_TOKEN;
        tok->text = "END";
    }
    return tok;
}

Lexer *lexer_init(char *input) {
    Lexer *lex = (Lexer*)malloc(sizeof(Lexer));
    lex->pos = 0;
    lex->content = input;
    return lex;
}

int main(int argc, char **argv) {
	char input[INPUT_BUFF_SIZE];
    while (1) {
        printf("ns> ");
        fgets(input, INPUT_BUFF_SIZE, stdin);
        Lexer *lex = lexer_init(input);
        Token *tok = lexer_next(lex);
        printf("Token:%s\tType:%d\n", tok->text, tok->type);
        while (tok->type != END_TOKEN) {
            tok = lexer_next(lex);
            printf("Token:%s\tType:%d\n", tok->text, tok->type);
        }
    }
    return 0;
}
