#include "monty.h"

/**
* monty_rotr - rotates the stack to the bottom
* @stack: pointer to the stack
* @line_number: current line number
*/
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;

	while (last->next != NULL)
		last = last->next;

	temp = last->prev;
	temp->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;

	(void)line_number;  /*Unused parameter*/
}
