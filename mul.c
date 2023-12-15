#include "monty.h"
/**
 * monty_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void monty_mul(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int stack_len = 0, mult_result;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		stack_len++;
	}
	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(config.file);
		free(config.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	mult_result = temp->next->n * temp->n;
	temp->next->n = mult_result;
	*head = temp->next;
	free(temp);
}
