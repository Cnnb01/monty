#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the opcode in the Monty script.
 */
void swap(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0, temp_value;

	temp = *head;
	while (temp)
	{
		temp =  temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	temp_value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_value;
}