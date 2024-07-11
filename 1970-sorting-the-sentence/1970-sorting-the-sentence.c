typedef struct Word {
    char* ptr;
    size_t cap;

    size_t seq;
} Word;

// Assumes ownership of `*ptr`!!
Word* word_new(char* ptr, size_t cap) {
    size_t len = strlen(ptr);
    if (len < 1) {
        free(ptr);
        return NULL;
    }

    size_t seq = (size_t) (ptr[len - 1] - '1');
    ptr[len - 1] = '\0';

    Word* ret = calloc(1, sizeof(Word));
    ret->ptr = ptr;
    ret->cap = cap;
    ret->seq = seq;

    return ret;
}

void word_drop(Word* self) {
    free(self->ptr);
    free(self);
}

Word* read_once(char** s) {
    size_t word_capacity = 1001;
    char* word_ptr = calloc(word_capacity, sizeof(char));

    size_t s_len = 0;
    sscanf(*s, "%s%n", word_ptr, &s_len);
    *s += s_len;

    return word_new(word_ptr, word_capacity);
}

#define loop for(;;)

char* sortSentence(char* s) {
    size_t word_vec_cap = 10001;
    Word** word_vec_ptr = calloc(word_vec_cap, sizeof(Word*));
    size_t word_vec_len = 0;

    loop {
        Word* word = read_once(&s);
        if (word == NULL) {
            break;
        }
        
        word_vec_ptr[word_vec_len] = word;
        word_vec_len += 1;
    }

    int _cmp(Word** op_0, Word** op_1) {
        return (*op_0)->seq - (*op_1)->seq;
    }

    qsort(
        word_vec_ptr, word_vec_len,
        sizeof(Word*), _cmp
    );

    size_t ret_cap = 10001;
    char* ret_ptr = calloc(ret_cap, sizeof(char));
    size_t ret_len = 0;

    for (size_t i = 0; i < word_vec_len; i += 1) {
        size_t _len = sprintf(
            ret_ptr + ret_len,
            "%s ", word_vec_ptr[i]->ptr
        );
        ret_len += _len;
        // word_print(word_vec_ptr[i]);
    }
    
    if (ret_len < 1) {
        return ret_ptr;
    }

    ret_ptr[ret_len - 1] = '\0';

    return ret_ptr;
}