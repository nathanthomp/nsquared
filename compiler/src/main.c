#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define INPUT_BUFF_SIZE 2048
#define TOKEN_BUFF_SIZE 256

typedef enum {
    UNKNOWN_TOKEN = 0,
    UNSUPPORTED_TOKEN,
    NUMBER_TOKEN,
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
    char text;
} Token;

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
			case '+':
				tok->type = PLUS_TOKEN;
				break;
			case '-':
				tok->type = MINUS_TOKEN;
				break;
			case '*':
				tok->type = STAR_TOKEN;
				break;
			case '/':
				tok->type = SLASH_TOKEN;
				break;
			case '{':
				tok->type = LBRACK_TOKEN;
				break;
			case '}':
				tok->type = RBRACK_TOKEN;
				break;
			case '(':
				tok->type = LPAREN_TOKEN;
				break;
			case ')':
				tok->type = RPAREN_TOKEN;
				break;
			default:
				tok->type = LETTER_TOKEN;
				break;
		}
	} else {
		tok->type = UNKNOWN_TOKEN;
	}

	(*pos)++;
	return tok;
}

int main(int argc, char **argv) {
	char input[INPUT_BUFF_SIZE];
    while (1) {
        printf("ns> ");
        fgets(input, INPUT_BUFF_SIZE, stdin);

		int pos = 0;
		while (input[pos] != '\n') {
			Token *tok = next_token(&pos, input);
			printf("Token:%c\tType:%d\n", tok->text, tok->type);
		}
    }
    return 0;
}
