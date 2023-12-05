#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - prints the different versions of 5 children
 * Return: 0 (success)
 */

int main()
{
	int i;
	int num_children;
	int status;
	pid_t  pid;

	for (i = 0; i < num_children; i++)
	{
		pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp("ls", "ls", "-l", "/tmp", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("childp process %d exited with status %d\n", pid, WEXITSTATUS(status));
		}
		else
		{
			printf("child process %d exited abnormally\n", pid);
		}
	}
	}
	return (0);
}
