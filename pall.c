#include "monty.h"
/**
* monty_pall - prints the stack
* @head: stack head
* @counter: not used
* Return: no return
*/

void monty_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;

	(void)counter;

	current = *head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
