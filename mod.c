#include "monty.h"
/**
 * monty_mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void monty_mod(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int stack_len = 0, mod_result;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		stack_len++;
	}
	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	mod_result = temp->next->n % temp->n;
	temp->next->n = mod_result;
	*head = temp->next;
	free(temp);
}
