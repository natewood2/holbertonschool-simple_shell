# Simple Shell Project

A simple shell project in C, typically involves creating a basic command-line interpreter that can execute user commands. This kind of project is often used for educational purposes to understand how operating systems handle processes and user inputs. Our task in this simple shell project is to implement the actual shell where we call out the path of executable commands written in by the user to execute them.

## Objectives:
Simple Shell project aims to deepen knowledge in critical aspects of UNIX shell operations and process management, focusing on the following key areas:

## Shell Mechanics:
- Gain insight into the functioning of a shell as an interpreter for command-line instructions, encompassing the intricacies of processing commands and managing user input.

## Utilizing the PATH:
- Understand how the shell uses the PATH environment variable to find and execute programs, and the importance of PATH in command execution.

## Process Handling and Execution:
- Learn the basics of handling and executing processes. This covers using system calls like fork, execve, and wait to control process lifecycles and execute commands.

## Repository Files

####
| Files  | Functions |
| :-----   | :--------- |
| `main.h` | File that contains all necessary headers that allows several functions to perform operations.
| `command.h` | File that contains all necessary headers that allows several functions to perform operations. |
| `main.c` |  File that calls an infinite loop to find the necessary path to call out.   |
| `check_path_execute.c` | File that checks for path and execution, to check if command is executable.  |
| `execute_command.c` | File that execute the command within the process, handling errors or statuses. |
| `find_command.c` |  File that search for the executable given command. |
| `get_environ.c` | File search for PATH environment variable and retrieves its value. It locates path of executable programs which it allows the shell to locate and execute commands entered by users. |
| `is_full_path.c` | File checks if given command is a full path or not. |
| `make_path.c` | File creates full path by combining directory path and command name. |
| `max_ppid`   |   File script that is used to find the process of the PPID.      |
| `README.md`  |   Description file of the project.       |
| `AUTHOR` | List of people who contributed to this project |


## Installation:
To access our Shell follow the following steps:
```bash
git clone (https://github.com/natewood2/holbertonschool-simple_shell.git)
```
To compile the given files use:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Once you compile it do this to run program:
```bash
./hsh
```
## Testing:
After installing the program and running it. It'll show a given prompt of ("$ "), in which you may then enter a command:

Example:

Prompt
```bash
$
```

Enter and execute command
```bash
/bin/ls
```

This would list files of the directory.

## Flowchart

![SHELL flowchart drawio](https://github.com/natewood2/holbertonschool-simple_shell/assets/144153433/021248ee-a649-4b14-aa3f-885923906c51)


## How 'Simple Shell' Works:

A simple shell allows the users to input commands to direct the system through breaking down the components which it runs into a infinite loop to locates the executable command listed in the system's PATH. It thens tokenlized the input to determind the wanted command. On each commands a child process is created which then, the parent process waits for the child process to be excecuted. As it locates the command's path it prints out the located memories.


## Authors

- Nathan Woods [[@natewood2](https://www.github.com/natewood2)]
- Kevin Vang [[@kvang2](https://www.github.com/kvang2)]


## Resource Information

🔗Links:
 - [Guide to code a simple shell in C](https://medium.com/@winfrednginakilonzo/guide-to-code-a-simple-shell-in-c-bd4a3a4c41cd)
 - [Making your own Linux Shell in C](https://www.geeksforgeeks.org/making-linux-shell-c/)
  - [Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
