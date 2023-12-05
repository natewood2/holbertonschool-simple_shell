#include "main.h"

int is_absolute_or_relative_path(const char *cmd) 
{
    return cmd[0] == '/' || (cmd[0] == '.' && (cmd[1] == '/' || (cmd[1] == '.' && cmd[2] == '/')));
}
