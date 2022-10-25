#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
    (void)env;
    if (argc == 2)
        sh_ps_lexcheck(argv[1]);
    return (0);
}