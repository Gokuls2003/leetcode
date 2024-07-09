// * Skip leading whitespace.
// * Optional Leading + - (tristate).
// * Stop at first non-numeric character.
// * Length: 0 - 200
// * Clamp: [-2^31...2^31-1]
// * Alphabet:
//   - 0-9
//   - ' '
//   - +
//   - -
//   - .

#include <stdint.h>

#define END '\0'
#define MAX_TOK_SIZE 200
#define POSITIVE true
#define NEGATIVE false

typedef struct token {
    char content[MAX_TOK_SIZE];
    int size;
    bool sign;
} token;

typedef struct parser {
    token t;
    int i;
    char *s;
} parser;

void init_token(token* t) {
    memset(t->content, 0, MAX_TOK_SIZE);
    t->size = 0;
    t->sign = POSITIVE;
}

void parser_init(parser* p, char* s) {
    p->s = s;
    p->i = 0;
    init_token(&p->t);
}

int dig(char c) {
    switch (c) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
    }

    assert(false);
    return 0;
}

bool is_digit(char c) { return isdigit(c); }

bool is_space(char c) {
    switch (c) {
        case ' ': return true;
        case '\n': return true;
        case '\t': return true;
        case '\r': return true;
    }
    return false;
}

char peek_char(parser *p) {
    return p->s[p->i];
}

char next_char(parser *p) {
    char c = p->s[p->i];
    if (c == END) return END;
    p->t.content[p->t.size] = c;
    p->t.size++;
    p->i++;
    return c;
}

void skip_char(parser *p) {
    char c = p->s[p->i];
    if (c == END) return;
    p->i++;
}

bool is_end(parser* p) { return peek_char(p) == END; }

void parse_sign(parser* p) { 
    switch (peek_char(p)) {
        case '-': {
            p->t.sign = NEGATIVE;
            skip_char(p);
            break;
        }
        case '+': {
            p->t.sign = POSITIVE;
            skip_char(p);
            break;
        }
    }
}

void parse_number(parser* p) {
    while (!is_end(p) && is_digit(peek_char(p))) {
        next_char(p);
    }
}

void skip_whitespace(parser* p) {
    while (!is_end(p) && is_space(peek_char(p))) {
        skip_char(p);
    }
}

void parse_token(parser* p) {
    init_token(&p->t);
    skip_whitespace(p);
    parse_sign(p);
    parse_number(p);
}


int token_value(token* t) {
    int v = 0;
    
    int MAX = 2147483647;
    // if (t->sign == NEGATIVE) {
    //     MAX = 2147483648;
    // }

    bool overflow = false;
    for (int i=0; i < t->size; i++) {
        int d = dig(t->content[i]);
        printf("%d %s\n", i, t->content);
        if (v <= (MAX - d) / 10) {
            v = v*10 + d;
        } else {
            v = MAX;
            overflow = true;
            break;
        }
    }

    if (t->sign == NEGATIVE) {
        v *= -1;
        if (overflow) {
            v-=1;
        }
    }
    
    return v;
}

int myAtoi(char* s) {
    if (s == NULL || s[0] == END) return 0;
    
    parser p;
    parser_init(&p, s);
    parse_token(&p);
    return token_value(&p.t);
}