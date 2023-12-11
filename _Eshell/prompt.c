#include <stdio.h>

/**
 * main - entry point
 * Return: 0 (success)
 */

int main(void)
{
char command[100];

while (1)
{
printf("$ ");
fflush(stdout);

if (fgets(command, sizeof(command), stdin) == NULL)
{
break;
}
printf("%s", command);
}

return 0;
}
