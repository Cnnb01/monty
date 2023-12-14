#include "monty.h"
/**
 * monty_sub - Subtract the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty script.
 *
 * If the stack has fewer than two elements, prints an error and exits.
 * Otherwise, subtracts the second top element
 * from the top element and updates the stack.
 */
void monty_sub(stack_t **head, unsigned int counter)
{
	charity
	stack_t *current;
	int result, node_count;

	current = *head;
	for (node_count = 0; current != NULL; node_count++)
		current = current->next;

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	result = current->next->n - current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}
