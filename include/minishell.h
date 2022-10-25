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
int sh_ps_isquate(char c);
void sh_ps_lexcheck(char *str);

#endif