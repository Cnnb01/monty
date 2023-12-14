#include "monty.h"
/**
* monty_div - Divide the second top element of the stack by the top element.
* @head: Pointer to the head of the stack.
* @counter: Line number in the Monty script.
*
* If the stack has fewer than two elements, prints an error and exits.
* Otherwise, divides the second top element by the top element
* and updates the stack. Handles division by zero.
*/
void monty_div(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int result, node_count;

	current = *head;
	for (node_count = 0; current != NULL; node_count++)
		current = current->next;

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}
