#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
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
