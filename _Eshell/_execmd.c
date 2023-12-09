#include "main.h"

/**
* _execmd - entry point
* @argv: argument vector
* Return: void
*/

void _execmd(char **argv)
{

char *_command, *actual_command = NULL;

if (argv)
{
/* get command */

_command = argv[0];

actual_command = get_location(_command);

/* execute actual command */

if (execve(actual_command, argv, NULL) == -1)
{
perror("Error:");
}
}
}
