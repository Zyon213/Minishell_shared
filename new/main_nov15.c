#include "../includes/sh_executor.h"

// displays a welcome message 

void    sh_ex_wcmessage()
{
    printf("%s\n","----------------------------------------");
    printf("%s\n","||                                    ||");
    printf("%s\n","||                                    ||");
    printf("%s\n","||      Welcome to Minishell         ||");
    printf("%s\n","||                                    ||");
    printf("%s\n","||                                    ||");
    printf("%s\n","----------------------------------------");
}

// count the number of string in the double arrray return the length

int sh_ex_doublelen(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

// frees all the memory of a double array

void sh_ex_freeall(char **str)
{
    int i;

    if (!str && !(*str))
        return ;
    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    str = NULL;
}

// view the all the environment variables

void sh_ex_viewenvp(t_shell_s *shell)
{
    int i;

    i = 0;
    while (shell->envp.envp[i])
    {
        printf("%s", shell->envp.key[i]);
        printf("%c",'=');
        printf("%s\n",shell->envp.value[i]);
        i++;
    }
}

// search for the key in the environment if found returns the value else return NULL

char *sh_ex_searchenvvar(t_shell_s *shell, char *key)
{
    int i;
    int len;
    
    len = ft_strlen(key);
    i = 0;
    while (shell->envp.key[i])
    {
        if (ft_strncmp(shell->envp.key[i], key, len) == 0)
            return (shell->envp.value[i]);
        i++;
    }
    return (NULL);
}

// allocates a memory for the key and value of environment variables 
// cutted out of sh_ex_creteenv() beacause it is long

int sh_ex_memkeyval(t_shell_s *shell)
{
    shell->envp.key = malloc(sizeof(char*) * (shell->envp.env_size + 1));
    if (!shell->envp.key)
        return 0;  
    shell->envp.value = malloc(sizeof(char*) * (shell->envp.env_size + 1));
    if (!shell->envp.value)
        return 0;
    return (1);
} 

// creates the environment variables form the env argument

void    sh_ex_createenvp(t_shell_s *shell, char **envp)
{
    int i;
    char **temp_env;

    shell->envp.envp = envp;
    shell->envp.env_size = sh_ex_doublelen(shell->envp.envp);

    if (sh_ex_memkeyval(shell))
    {
        i = 0;
        while (shell->envp.envp[i])
        {
            temp_env = ft_split(shell->envp.envp[i], '=');
            shell->envp.key[i] = temp_env[0];
             if (!temp_env[1])
                shell->envp.value[i] = ft_strdup("");
            else 
                shell->envp.value[i] = temp_env[1];
    // free the memory allocated by ft_split() nad ft_strdup()
    //        sh_ex_freeall(temp_env);
            i++;
        }

        shell->envp.key[i] = NULL;
        shell->envp.value[i] = NULL;
    }
}

// initialize the shell values home and path variables
// and free home becuase it use ft_strdup to allocate memory
// and free path it uses allocate memory

void sh_ex_initshell(t_shell_s *shell, char **envp)
{
    int i;
    char *all_path;
    char **path;
    char *home;

    sh_ex_createenvp(shell, envp);
    home = sh_ex_searchenvvar(shell, "HOME");
    shell->home = ft_strdup(home);
    all_path = sh_ex_searchenvvar(shell, "PATH");
    path = ft_split(all_path, ':');
/*     shell->path = malloc(sizeof(char *) * (sh_ex_doublelen(path) + 1));
    if (!shell->path)
        return ; */
    i = -1;
    while (path[++i])
        shell->path[i] = path[i];
//    sh_ex_freeall(path);
    shell->path[i] = 0;  
}

int main(int argc, char **argv, char **envp)
{
    t_shell_s shell;

    sh_ex_wcmessage();

    sh_ex_initshell(&shell, envp);


     int i = 0;
    while (shell.path[i])
        printf("%s\n", shell.path[i++]); 

    sh_ex_freeall(shell.envp.key);
    sh_ex_freeall(shell.envp.value);
//    sh_ex_freeall(shell.path);
    free(shell.home);
 
    return (0);
} 