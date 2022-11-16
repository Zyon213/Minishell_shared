#ifndef SH_EXECUTOR_H
#define SH_EXECUTOR_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// struct for the environment variables

typedef struct t_env_s
{
    int env_index;
    int env_size;
    char **envp;
    char **key;
    char **value;
}   t_env_s;

// struct for the command variables

typedef struct t_shell_s
{
    char *command;
    char *home;
    char **path;
    struct t_env_s envp;
}   t_shell_s;

void    sh_ex_wcmessage();
int sh_ex_doublelen(char **str);
void sh_ex_freeall(char **str);
int sh_ex_memkeyval(t_shell_s *shell);
void    sh_ex_createenvp(t_shell_s *shell, char **envp);
void sh_ex_viewenvp(t_shell_s *shell);
char *sh_ex_searchenvvar(t_shell_s *shell, char *key);
void sh_ex_initshell(t_shell_s *shell, char **envp);


#endif