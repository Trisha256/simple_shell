#include "main.h"
/**
* main - entry point
* @ac: argument count
* @argv: argument vector
* Return: int
*/
int main(int ac, char **argv)
{
char *prompt = "(_Eshell) $ ", *command = NULL, *command_copy = NULL;
size_t n = 0;
ssize_t nchars_read;
char *_token;
const char *delim = " \n";
int i, num_tokens = 0;
(void)ac;

while (1)
{
printf("%s", prompt);
nchars_read = getline(&command, &n, stdin);
if (nchars_read == -1)
{
printf("Exiting shell....\n");
return (-1);
}
command_copy = malloc(sizeof(char) * nchars_read);
if (command_copy == NULL)
perror("tsh: memoray allocation error");
return (-1);
strcpy(command_copy, command);
_token = strtok(command, delim);
while (!_token)
num_tokens++;
_token = strtok(NULL, delim);
num_tokens++;
argv = malloc(sizeof(char *) * num_tokens);
_token = strtok(command_copy, delim);
for (i = 0; _token != NULL; i++)
argv[i] = malloc(sizeof(char) * strlen(_token));
strcpy(argv[i], _token);
_token = strtok(NULL, delim);
argv[i] = NULL;
_execmd(argv);
}
free(command);
free(command_copy);
return (0);
}
