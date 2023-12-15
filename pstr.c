#include "monty.h"

/**
* monty_pstr - prints the string starting at the top of the stack
* @stack: pointer to the stack
* @line_number: current line number
*/
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *c = *stack;

	while (c != NULL && c->n != 0 && (c->n >= 0 && c->n <= 127))
	{
		putchar(c->n);
		c = c->next;
	}

	putchar('\n');
	(void)line_number;/*unused variable*/
}
