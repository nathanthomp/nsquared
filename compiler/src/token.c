#include <stdlib.h>
#include "include/token.h"

token_t *token_init() {
    token_t *tok = (token_t*)malloc(sizeof(token_t));
    return tok;
}
