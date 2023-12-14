#include "monty.h"

/**
* pop - Removes the top element of the stack.
* @head: Pointer to the head of the stack.
* @counter: Line number of the opcode in the Monty script.
*/
void pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
