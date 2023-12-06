#ifndef MAIN_H
#define MAIN_H

#define MAX_ARGS 10

/* Include necessary libraries for standard I/O, memory management, etc. */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

extern char **environ;
/* Define the main function, which is the entry point of the program. */
int main(void);

char *_strtok(char *str, const char *delim);
char *get_environ(char **env);
char *construct_full_path(const char *dir, const char *cmd);
char *find_command_in_path(const char *cmd);
int can_execute_command(const char *full_path);
void process_command(char *buffer);
int tokenize_input(char *buffer, char **args, int max_args);
int check_input_failure(ssize_t length, char *buffer);
ssize_t read_input_line(char **buffer, size_t *bufferSize);
int is_absolute_or_relative_path(const char *cmd);
int is_full_path(const char *cmd);
void trim_trailing_spaces(char *str);
int execute_command(char *command, char **args);
int check_path_and_execute(const char *cmd, char **args);


#endif
