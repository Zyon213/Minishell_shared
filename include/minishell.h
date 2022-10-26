#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../libft/libft.h"



int sh_ps_isdelimeter(char c);
int sh_ps_isnum(char c);
int sh_ps_isspechar(char c);
int sh_ps_ischar(char c);
int sh_ps_isquote(char c);
void sh_ps_lexcheck(char *str);
void sh_ps_token(char *cmd);
char *sh_ps_isquoted(char *str);
int sh_ps_issinglequote(char c);
int sh_ps_isdoublequote(char c);
int sh_ps_isescape(char c);
int sh_ps_issinglequoted(char *str, int i);

#endif