#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
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
return 0;
}
