#include "monty.h"

/**
* monty_add - Adds the top two elements of the stack.
* @head: Pointer to the head of the stack.
* @counter: Line number of the opcode in the Monty script.
*/
void monty_add(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	temp->next->n += temp->n;
	*head = temp->next;
	(*head)->prev = NULL;
	free(temp);
}
