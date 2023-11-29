
/*
 * This is a header file for the main function of a C program.
 * It includes necessary libraries and defines the main function.
 */

#ifndef MAIN_H
#define MAIN_H

/* Include necessary libraries for standard I/O, memory management, etc. */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

extern char **environ;
/* Define the main function, which is the entry point of the program. */
int main(int ac __attribute__((unused)), char **av);

char *_strtok(char *str, const char *delim);

#endif 
