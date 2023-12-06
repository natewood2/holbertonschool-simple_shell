#include "main.h"

int is_full_path(const char *cmd) 
{
    return strchr(cmd, '/') != NULL;
}
