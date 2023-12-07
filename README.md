# Simple Shell Project
![dall__e_2023-12-07_09 44 54_-_a_creative_and_intense_image_featuring_a_simple_shell-style_linux_terminal_wreaking_havoc_in_a_city _the_terminal__resembling_a_classic_command_line_i_720](https://github.com/natewood2/holbertonschool-simple_shell/assets/144153433/f4803a87-d3fa-4d98-9043-091301a48a52)

A simple shell project in C, typically involves creating a basic command-line interpreter that can execute user commands. This kind of project is often used for educational purposes to understand how operating systems handle processes and user inputs. Our task in this simple shell project is to implement the actual shell where we call out the path of executable commands written in by the user to execute them.

## Objectives:
Simple Shell project aims to deepen knowledge in critical aspects of UNIX shell operations and process management, focusing on the following key areas:

## Shell Mechanics:
- Gain insight into the functioning of a shell as an interpreter for command-line instructions, encompassing the intricacies of processing commands and managing user input.

## Utilizing the PATH:
- Understand how the shell uses the PATH environment variable to find and execute programs, and the importance of PATH in command execution.

## Process Handling and Execution:
- Learn the basics of handling and executing processes. This covers using system calls like fork, execve, and wait to control process lifecycles and execute commands.


## How 'Simple Shell' Works:

A simple shell enables users to input commands, directing the system by breaking down components and running them in an infinite loop. This loop searches for the executable command in the system's PATH. The input is then tokenized to determine the desired command. For each command, a child process is created. The parent process waits for the execution of this child process. As the command's path is identified, the shell outputs the located memory addresses.

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


# Installation:
Follow these steps to access our Shell:
```bash
git clone (https://github.com/natewood2/holbertonschool-simple_shell.git)
```
To compile the given files use:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Once compiled, follow this step to run program:
```bash
./hsh
```
# Testing:
After installing and running the program, it will display a prompt with the symbol "$", At this point, you may enter a command.

### Prompt:
```bash
$
```

### Enter and execute command:
```bash
/bin/ls
```

This command will list the files of the directory. We encourage you to experiment with different commands in our simple shell to discover its versatile functionalities and to enhance your understanding of how it operates.

## Flowchart

![Shell project flowchart update drawio (1)](https://github.com/natewood2/holbertonschool-simple_shell/assets/144153433/64195d7a-423d-4a84-9be3-a2ffced11e4a)


## Authors

- Nathan Woods [[@natewood2](https://www.github.com/natewood2)]
- Kevin Vang [[@kvang2](https://www.github.com/kvang2)]


## Resource Information

🔗Links:
 - [Guide to code a simple shell in C](https://medium.com/@winfrednginakilonzo/guide-to-code-a-simple-shell-in-c-bd4a3a4c41cd)
 - [Making your own Linux Shell in C](https://www.geeksforgeeks.org/making-linux-shell-c/)
  - [Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
