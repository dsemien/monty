
#include "monty.h"

/**
 * c_add - adds the top two elements of the stack.
 * @stack: double linked list
 * @line_number: line number of opcode
 */
void c_add(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		(*stack)->next->n += (*stack)->n;
		c_pop(stack, line_number);
	}
	else
	{
		printf("L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
}
