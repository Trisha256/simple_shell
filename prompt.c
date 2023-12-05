#include <stdio.h>
#include <string.h>

/**
 * main - prints "$ ".
 * Return: 0 (success)
 */

int main()
{
	printf("$ ");

	char command[256];
	
	fgets(command, sizeof(command), stdin);

	printf("%s\n", command);
	return (0);
}
