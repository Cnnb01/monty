#include "monty.h"
/**
* addqueue - add node to the tail stack
* @node_value: new_value
* @head: head of the stack
* Return: no return
*/
void addqueue(stack_t **head, int node_value)
{
	charity
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = node_value;
	new_node->next = NULL;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	if (!current)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current->next = new_node;
		new_node->prev = current;
	}
}
