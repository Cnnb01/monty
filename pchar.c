#include "monty.h"

/**
* monty_pchar - prints the character at the top of the stack
* @stack: pointer to the stack
* @line_number: current line number
*/
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(config.file);
		free(config.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(config.file);
		free(config.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

