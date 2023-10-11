#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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
char *args[] = {command, NULL};
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
/**
 * main - Entry point for the shell program.
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
execute_command(command);
free(command);
}
return (0);
}
