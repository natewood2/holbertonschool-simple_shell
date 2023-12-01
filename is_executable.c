#include "command.h"

int can_execute_command(const char *full_path) 
{
    return (access(full_path, F_OK) != -1 && access(full_path, X_OK) != -1);
}

