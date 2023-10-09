#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
printf("#cisfun$ ");
}
/**
 * read_command - Read a command from the user.
 *
 * Return: A pointer to the command string or NULL on EOF.
 */
char *read_command(void)
{
char *command = NULL;
size_t bufsize = 0;
if (getline(&command, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
free(command);
return (NULL);
}
perror("getline");
exit(EXIT_FAILURE);
}
return (command);
}
/**
 * execute_command - Execute a command using execve.
 *
 * @command: The command to execute.
 *
 * If the command exists in the PATH, it is executed in a child process.
 * If the command does not exist, an error message is printed.
 */
void execute_command(char *command)
{
pid_t pid;
char *args[2];
args[0] = command;
args[1] = NULL;
if (access(command, X_OK) == 0)
{
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
if (execve(command, args, NULL) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(pid, &status, 0);
}
}
else
{
printf("%s: command not found\n", command);
}
}
/**
 * main - Entry point for the shell program.
 *
 * This function displays the shell prompt, reads user commands,
 * and executes them using the execute_command function.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
char *command;
while (1)
{
display_prompt();
command = read_command();
if (command == NULL)
{
printf("\n");
break;
}
command[strlen(command) - 1] = '\0';
/* Check if the command is "exit" and exit the shell */
if (strcmp(command, "exit") == 0)
{
free(command);
exit(EXIT_SUCCESS);
}
execute_command(command);
free(command);
}
return (0);
}

