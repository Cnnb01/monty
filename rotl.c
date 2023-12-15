#include "monty.h"

/**
* monty_rotl - rotates the stack to the top
* @stack: pointer to the stack
* @line_number: current line number
*/
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = temp->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	last->next = temp;
	temp->prev = last;

	(void)line_number;  /*Unused parameter*/
}
