#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_word_s
{
    int len;
    char *name;
    struct t_word_s *next;
}   t_word_s;

int errro_msg(char *str, int i)
{
    printf("%s\n", str);
    return (i);
}

void display_node(t_word_s *word)
{
    int i = 0;
    while(word)
    {
        printf("[%04d] %s [%d]\n", i++, word->name, word->len);
        word = word->next;
    }
}

void    free_node(t_word_s *word)
{
    while (word)
    {
        t_word_s *cur = word;
        if (cur->name)
            free(cur->name);
        word = word->next;
    }

    free(word);
}

t_word_s *new_word(char *str)
{
    t_word_s *head = malloc(sizeof(t_word_s));
    if (!head)
        errro_msg("Error allocating new node memory", 1);
    
    int len = strlen(str);
    char *name = malloc(sizeof(char) * (len + 1));

    if (!name)
    {
        free(head);
        errro_msg("Error allocating data memory", 2);
    }

    strcpy(name, str);
    head->name = name;
    head->len = len;
    head->next = NULL;

    return head;
}

t_word_s *add_node(t_word_s **word, char *str)
{
    t_word_s *head,*head1, *tail;
    head = *word;
    int i = 0;

    head1 = head;

    if (!str)
    {
        if (head)
            return (*word);
        else
            return NULL;
    }
    else
    {
        if (!head)
            head = new_word(str);
        else
        {
            while (head->next != NULL)
                head = head->next;
            
            tail = new_word(str);
            head->next = tail;

            free(tail);
        }
        *word = head1;

    }

/* 
    if (!head)
    {
        if (!str)
            errro_msg("Error null string and node", 1);
        else
            head = new_word(str);
    }
    else
    {
        while (head->next != NULL)
        {
            printf("%s\n", head->name);
            head = head->next;
        }
        tail = new_word(str);
        head->next = tail;
    }
    free(tail);
    *word = head; 
    */

    return (*word);
}

int main(int argc, char **argv)
{
    t_word_s *word, *word1, *word2, *word3;
    char name[] = "yonas";
//    word = new_word(name);
//    display_node(word);

    add_node(&word, "yohannes");
//    display_node(word);

     add_node(&word, "gebremichal");
 //   display_node(word);

    add_node(&word, "medihin");
 //   display_node(word);

    add_node(&word, "samson");
    display_node(word); 

    return (0);
}