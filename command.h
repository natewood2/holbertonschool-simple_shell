#ifndef COMMAND_H
#define COMMAND_H

/* Standard library headers */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/* Prototypes */
char *find_command_in_path(const char *cmd);
int can_execute_command(const char *full_path);

#endif
