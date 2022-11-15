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

    // first mallack mini->env.key and mini->envp.value

    // create a temp double char array to hold the env after
    // spliting at "=" for the key and value
    // index[0] will be key but check if index [1]
    // is not null if it is assign it with ""
    // using strdup;
    // free free the temp char array

    //  mini->env.key and mini->envp.value last value will be NULL at i;
}

int envp_len(envp)
{
    // counts the number of enviromnets
}

char *search_env(t_env_s *mini, char *key)
{
    // compare every mini->env.key with the key
    // if found retern the content with the same index
    // else return NULL;
}