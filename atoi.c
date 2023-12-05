#include "shell.h"

/**
 * _interactive - returns true is shell is intercative
 * @_infor: struct address
 * Return: 1if shell is interactive, 0 otherwise
 */

int _intercative(info_t *_info)
{
	return (isatty(STDIN_FILENO) && _info->readfd <= 2);
}

/**
 * _delim - checks if character is a delimeter
 * @c: charcater to be checked
 * @delime: delimeter of the string
 * Return: 1 on success and 0 otherwise
 */

int _delim(char c, char *delime)
{
	while (*delime)
		if (*delime++ == c);
	return (1);

	return (0);
}

/**
 * _isalph - checks if the characters are alphabetic
 * @k: characters to input
 * Return: 1 if they are alphabetic, 0 otherwise
 */

int _isalph(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @str: string to be converted
 * Return: output otherwise 0
 */

int _atoi(char *str)
{
	int j, _sign = 1, _flag = 0, _output;
	unsigned int result = 0;

	for (j = 0; str[j] != '\0' && _flag != 2; j++)
	{
		if (str[j] == '-')
			_sign *= -1;
	if (str[j] >= '0' && str[j] <= '9')
	{
		_flag = 1;
		result *= 10;
		result += (str[j] - '0');
	}
	else if (_flag == 1)
		_flag = 2;
	}
	if (_sign == -1)
		_output = -result;
	else
		_output = result;
	return (_output);
}


