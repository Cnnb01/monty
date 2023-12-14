#include "monty.h"

/**
* monty_push - Adds a node to the stack.
* @head: Pointer to the head of the stack.
* @counter: Line number.
*
* Return: No return value.
*/
void monty_push(stack_t **head, unsigned int counter)
{
	int value, index = 0, invalid = 0;

	if (!config.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (config.arg[0] == '-')
		index++;

	for (; config.arg[index] != '\0'; index++)
	{
		if (config.arg[index] > '9' || config.arg[index] < '0')
			invalid = 1;
	}

	if (invalid == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	value = atoi(config.arg);

	if (config.lifi == 0)
		addnode(head, value);
	else
		addqueue(head, value);
}
