#include "monty.h"
/**
 * monty_pint - Prints the value at the top of the stack.
 * @head: Pointer to the stack's top
 * @counter: Line number in the Monty bytecode file
 * Return: No return value
 */
charity
void monty_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
