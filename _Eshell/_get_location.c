#include "main.h"
/**
* get_location - fuction takes the command (ls)
* that was passed and returns the path (usr/bin/ls)
* @command: command passed
* Return: path
*/

char *get_location(char *command)
{
char *path, *path_copy, *path_token, *file_path;
int command_length, directry_length;
struct stat buff;

path = getenv("PATH");

if (path)
{
path_copy = strdup(path);
command_length = strlen(command);
path_token = strtok(path_copy, ":");
while (path_token != NULL)
{
directry_length = strlen(path_token);
file_path = malloc(command_length + directry_length + 2);
strcpy(file_path, path_token);
strcat(file_path, "/");
strcat(file_path, command);
strcat(file_path, "\0");
if (stat(file_path, &buff) == 0)
{
free(path_copy);
return (file_path);
}
else
{
free(file_path);
path_token = strtok(NULL, ":");
}
}
free(path_copy);

if (stat(command, &buff) == 0)
{
return (command);
}
return (NULL);
}
return (NULL);
}
