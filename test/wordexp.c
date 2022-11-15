#include "shell.h"

t_word_s *make_word(char *str)
{
    t_word_s *word = malloc(sizeof(t_word_s));
    if (!word)
        return NULL;
    size_t len = strlen(str);
    char *data = malloc(len + 1);

    if (!data)
    {
        free(word);
        return (NULL);
    }

    strcpy(data, str);
    word->data = data;
    word->len = len;
    word->next = NULL;
    
    return word;
}

void free_all_words(t_word_s *first)
{
    while (first)
    {
        t_word_s *cur = first;
        if (cur->data)
            free(cur->data);
        first->next = first;
    }
    free(first);
}
