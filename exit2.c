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
 */
void execute_command(char *command)
{
pid_t pid;
char *args[MAX_INPUT_SIZE];
int arg_count = 0;
/* Tokenize the command into arguments */
char *token = strtok(command, " ");
while (token != NULL)
{
args[arg_count++] = token;
token = strtok(NULL, " ");
}
args[arg_count] = NULL;
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
/* Try to execute the command using the PATH */
if (execvp(args[0], args) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(pid, &status, 0);
}
}
/**
* exit_shell - Exits the shell.
*/
void exit_shell(void)
{
exit(EXIT_SUCCESS);
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
/* Remove the trailing newline character */
command[strlen(command) - 1] = '\0';
if (strcmp(command, "exit") == 0)
{
exit_shell();
}
else
{
execute_command(command);
}
free(command);
}
return (0);
}
