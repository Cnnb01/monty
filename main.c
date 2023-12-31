#define _GNU_SOURCE
#include "monty.h"

config_t config = {NULL, NULL, NULL, 0};

/**
 * main - montyInterpreter, Interpret Monty code from a file
 * @argc: Number of command-line arguments
 * @argv: Array of strings containing command-line arguments
 * Return: 0 on successful interpretation, other values on error
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	config.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		config.content = content;
		counter++;
		if (read_line > 0)
		{
			/*process_line(content);*/
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	clear_stack(stack);
	fclose(file);
return (0);
}
