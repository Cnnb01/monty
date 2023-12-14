#include "monty.h"

/**
* clear_stack - Frees the memory allocated for a doubly linked list.
* @head: Pointer to the head of the stack.
*
* This function frees the memory of each node in the doubly linked list,
* starting from the head of the stack.
*/
void clear_stack(stack_t *head)
{
	stack_t *current_node;

	current_node = head;
	while (current_node)
	{
		stack_t *next_node = current_node->next;

		free(current_node);
		current_node = next_node;
	}
}
