#ifndef monty_h
#define monty_h
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/**
*struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;

	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
* struct config_s - variables -args, file, line content
* @arg: value
* @file: pointer to monty file
* @content: line content
* @lifi: flag change stack <-> queue
* Description: carries values through the program
*/
typedef struct config_s
{
	char *arg;

	FILE *file;
	char *content;

	int lifi;

} config_t;

extern config_t config;

/**
*struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
* Description: opcode and its function
*for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;

	void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;
void clear_stack(stack_t *head);
void monty_pop(stack_t **head, unsigned int counter);
void monty_swap(stack_t **head, unsigned int counter);
void monty_add(stack_t **head, unsigned int counter);
void monty_nop(stack_t **stack, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void monty_push(stack_t **head, unsigned int counter);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int n);


#endif
