#include "monty.h"

/**
 * addnode - Adds a new node to the top of the stack.
 * @head: A pointer to the head of the stack.
 * @n: The value to be stored in the new node.
 *
 * This function creates a new node with the given value and adds it to the
 * top of the stack pointed to by @head.
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *current_top;

	current_top = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (current_top)
		current_top->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
