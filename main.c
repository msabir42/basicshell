#include "shell.h"

int main(int argc, char *argv[]){
    (void)argc,(void)argv;
     char* prompt;
     while (1){
        prompt = readline("$minishell>");
        if (!prompt)
        {
            write(1,"Cant read !! ",14);
            return 1;
        }
        if (prompt)
        {
            read_history(prompt);
        }
        
        free(prompt);
     }
    return 0;
}

