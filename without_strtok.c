#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024

/**
 * _getline - Read a line of text from standard input.
 *
 * Return: A pointer to the input line, or NULL if there is an error or EOF.
 */
char *_getline(void)
{
size_t bufsize = 0;
char *line = NULL;
ssize_t nread;
nread = getline(&line, &bufsize, stdin);
if (nread == -1)
if (feof(stdin))
{
free(line);
return (NULL);
{
perror("_getline");
exit(EXIT_FAILURE);
}
return (line);
}
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
char *command = _getline();
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
char *token = command;
while (*token != '\0')
{
/* Skip leading spaces */
while (*token == ' ' || *token == '\t')
{
token++;
}
if (*token != '\0')
{
args[arg_count++] = token;
}
/* Find the end of the argument */
while (*token != '\0' && *token != ' ' && *token != '\t' && *token != '\n')
{
token++;
}
if (*token != '\0')
{
*token = '\0';
token++;
}
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
 * print_environment - Print the current environment variables.
 */
void print_environment(void)
{
extern char **environ;
int i = 0;
while (environ[i] != NULL)
{
printf("%s\n", environ[i]);
i++;
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
/* Remove the trailing newline character */
command[strlen(command) - 1] = '\0';
if (strcmp(command, "exit") == 0)
{
exit_shell();
}
else if (strcmp(command, "env") == 0)
{
print_environment();
}
else
{
execute_command(command);
}
free(command);
}
return (0);
}
