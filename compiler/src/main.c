#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define INPUT_BUFF_SIZE 2048
#define TOKEN_BUFF_SIZE 256

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
} Token_Type;

typedef struct {
    Token_Type type;
    char *text;
} Token;

typedef struct {
    size_t pos;
    const char* content;
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
        } else if (isdigit(current)) {
            while (lexer_peek(lex) == NUMBER_TOKEN) {
                lex->pos++;
            }
            tok->type = NUMBER_TOKEN;
            tok->text = "NUMBER";
        } else if (isalpha(current)) {
            /*
            int buff_index = 0;
            char buff[TOKEN_BUFF_SIZE];
            buff[buff_index] = current;
            */
            // while [:word:]
            while (lexer_peek(lex) == LETTER_TOKEN) {
                /*
                current = lex->content[lex->pos++];
                printf("current = %c\n", current);
                printf("pos = %ld\n", lex->pos);
                buff[buff_index++] = current;
                */
                lex->pos++;
            }
            tok->type = LETTER_TOKEN;
            tok->text = "LETTER";
        } else {
            switch (current) {
                case '+':
                    tok->type = PLUS_TOKEN;
                    tok->text = "+";
                    break;
                case '-':
                    tok->type = MINUS_TOKEN;
                    tok->text = "-";
                    break;
                case '*':
                    tok->type = STAR_TOKEN;
                    tok->text = "*";
                    break;
                case '/':
                    tok->type = SLASH_TOKEN;
                    tok->text = "/";
                    break;
                case '{':
                    tok->type = LBRACK_TOKEN;
                    tok->text = "{";
                    break;
                case '}':
                    tok->type = RBRACK_TOKEN;
                    tok->text = "}";
                    break;
                case '(':
                    tok->type = LPAREN_TOKEN;
                    tok->text = "(";
                    break;
                case ')':
                    tok->type = RPAREN_TOKEN;
                    tok->text = ")";
                    break;
                default:
                    tok->type = UNSUPPORTED_TOKEN;
                    tok->text = "UNSUPPORTED";
                    break;
            }
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
