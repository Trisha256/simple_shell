#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints the av without including the ac
 * @av: argument vector
 * @ac: argument count
 * Return: 0 (success)
 */

int main(int ac __attribute__ ((unused)), char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}

