#include "monty.h"

/**
* process_line - Process a line of Monty bytecode.
* @line: The line to process.
*/
void process_line(char *line)
{
	char *trimmed_line = trim_whitespace(line);

	if (trimmed_line[0] == '\0' || trimmed_line[0] == '#')
	{

		return;
	}

	free(trimmed_line);
}

/**
* trim_whitespace - Remove leading and trailing whitespaces from a string.
* @str: The string to trim.
* Return: A pointer to the trimmed string.
*/
char *trim_whitespace(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
	{

		str++;
	}

	if (*str == '\0')
	{
		return (str);
	}

	 end = str + strlen(str) - 1;

	while (end > str && isspace((unsigned char)*end))
	{

		end--;
	}

	*(end + 1) = '\0';

	return (str);
}
