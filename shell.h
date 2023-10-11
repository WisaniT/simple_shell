#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024

/* Function prototypes */
char *_getline(void);
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void exit_shell(void);
void print_environment(void);
void set_env_variable(const char *name, const char *value);

#endif /* SHELL_H */
