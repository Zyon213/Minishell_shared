#include "../include/minishell.h"

 int main(int argc, char **argv, char **env)
{
    (void)env;
    if (argc == 2)
    {
    //    sh_ps_lexcheck(argv[1]);
    //    sh_ps_token(argv[1]);
        printf("%s\n", sh_ps_isquoted(argv[1]))
;    }
    return (0);
} 
