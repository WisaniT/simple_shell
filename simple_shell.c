#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

/**
 * @brief Main function for a simple shell.
 *
 * This function implements a basic shell that takes user commands and executes them.
 * It displays a prompt, reads user input, executes the command, and repeats until the user exits.
 *
 * @return 0 on success, non-zero on failure.
 */
int main(void)
{
    char input[MAX_INPUT_SIZE];

    while (1)
    {
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break; // Exit on Ctrl+D (end of file)
        }

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            break; // Exit the shell
        }

        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
        }
        else if (pid == 0)
        {
            // Child process
            if (execlp(input, input, (char *)NULL) == -1)
            {
                perror(input);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Parent process
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
            {
                fprintf(stderr, "%s: command not found\n", input);
            }
        }
    }

    return (0);
}

