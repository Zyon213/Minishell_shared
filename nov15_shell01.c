// create a struct for the enviroment variables

typedef struct t_env_s
{
    char **envp; // the whole environments
    int len;     // length of the enviroments
    char **key;
    char **value;
    int index;
} t_env_s;

// start with the main function that accepts argv and environment

typedef struct t_mini_s
{
    char *home;
    char **path;
    // declare all the variables here
    struct t_env_s envp;

} t_mini_s;

int main(int argc, char **argv, char **envp)
{
    // declare and initialize the main struct (that contain all the variables)
    t_mini_s mini;

    // print wel com screen

    screen_init();

    // call the function that will initialize the values
    // currenly there are no value to be initialized

    mini_initialize(mini, envp);
    // initialize the prompt with wel come message

    //------------------------

    // create while (1)
    {
        // create infile and outfile variables in main struct
        // and assign it to STDOUT and STDIN
    }

    // read the command using readline
    read_line(mini)
}

void screen_init()
{
    printf("%s\n", "welcome");
}

void mini_initialize(t_mini_s *mini, char **envp)
{
    // create the enviroment variables key and value;
    create_envp(mini, envp);

    // search for "HOME" in the struct key and assign it
    // to mini->home;
    mini->home; // mini->home = strdup(find_env(mini->env.key, "HOME"))

    // search for the PATH in the environment key and take
    // the value and split it at ":" and assign it to the mini->path

    initialize_path(mini);
}

void create_envp(t_env_s *mini, char **envp)
{
    // count the number of env
    envp_len(envp);

    // assign mini->envp to envp
    //------------------------

    // use void and if null exit_FAILURE
    //------------------------
    // first mallack mini->env.key and mini->envp.value

    // create a temp double char array to hold the env after
    // spliting at "=" for the key and value
    // index[0] will be key but check if index [1]
    // is not null if it is assign it with ""
    // using strdup;
    // free the temp char array
    //------------------
    // temp_env = NULL after freeing since we don't
    // use NULL in the function

    // use ft_strdup for all key and content
    //------------------------
    //  mini->env.key and mini->envp.value last value will be NULL at i;
}

int envp_len(envp)
{
    // counts the number of enviromnets
    //------------------------
    // for len instead of return int
    // assign it to env-len_size
}
//------------------------
char *search_env(t_env_s *mini, char *key)
{
    // compare every mini->env.key with the key
    // if found retern the content with the same index
    // else return NULL;
}

//------------------------
void free(**array)
{
    // while (array[i] )
    // free the elements free(array[i])
    // and assign it to NULL array[i] = NULL
    // and free the main array free(array)
}

void free2(**array)
{
    //     // free the elements free(array[i])
    // assing it to NULL
}

void readline(shell)
{
    // create a variable in mini readline
    // create prompt char *prompt
    create_prompt() return the current direcotory
    // run signal function to accept signals
    // read the line
    // assign read line to mini->readline
    // if not null add it to history
    // free the prompt
}

char *create_prompt()
{
    char *prompt
        // char *buf[] use geekstip to
        //  use getcwd funcition
        //  return current direictory
        //  and sign $ or >> at the end using ft_strjoin
        //  get buf
        //  dup color
        //  join color and buf
        //  free buf
        // joint with sign
        return prompt
}

/*
void	run_signals(int sig)
{
    if (sig == 1)
    {
        signal(SIGINT, restore_prompt);
        signal(SIGQUIT, SIG_IGN);
    }
    if (sig == 2)
    {
        signal(SIGINT, ctrl_c);
        signal(SIGQUIT, back_slash);
    }
    if (sig == 3)
    {
        printf("exit\n");
        exit(0);
    }
}

void	restore_prompt(int sig)
{
    g_ret_number = 130;
    write(1, "\n", 1);
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
    (void)sig;
}

void	ctrl_c(int sig)
{
    g_ret_number = 130;
    write(1, "\n", 1);
    (void)sig;
}

void	back_slash(int sig)
{
    g_ret_number = 131;
    printf("Quit (core dumped)\n");
    (void)sig;
}
 */