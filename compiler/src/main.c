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
    if (*pos >= strlen(input))
        return NULL;
    /* pos < input.len */
    Token *tok = (Token*)malloc(sizeof(Token));
    char current = input[*pos];
    if (isalpha(current)) {
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
                /* Error unsupported token */
                tok->type = UNSUPPORTED_TOKEN;
                break;
        }
        tok->text = current;
    } else if (isdigit(current)) {
        /* Numeric */
        tok->type = NUMBER_TOKEN;
        tok->text = current;
        //while (isdigit(input[(*pos)++]))
        //    tok->text = buff;
    }
    else if (isblank(current)) {
        tok->type = BLANK_TOKEN;
        tok->text = current;
    }
    else {
        /* Error unknown token */
        tok->type = UNKNOWN_TOKEN;
        tok->text = current;
    }
    (*pos)++;
}

void tokenize(const char *input) {
    int pos = 0;
    Token *tok = next_token(&pos, input);
    do {
        printf("Token:%c\tType:%d\n", tok->text, tok->type);
        tok = next_token(&pos, input);
    } while (tok);
}

char input[INPUT_BUFF_SIZE];

int main(int argc, char **argv) {
    /* REPL */ 
    printf("NSquared\n");
    while (1) {
        fputs("ns> ", stdout);
        fgets(input, INPUT_BUFF_SIZE, stdin);
        tokenize(input); 
    }
    return 0;
}
