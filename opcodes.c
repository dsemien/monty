#include "monty.h"
int c_fetch = 0;
/**
 * c_push - pushes an element to the stack
 * @stack: double linked list
 * @line_number: line number of opcode
 */
void c_push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
   stack_t *newNode;

   newNode = malloc(sizeof(stack_t));
   if (newNode == NULL)
   {
	   printf("Error: malloc failed\n");
	   exit(EXIT_FAILURE);
   }
   newNode->n = c_fetch;
   if (*stack == NULL)
   {
	   newNode->next = NULL;
	   newNode->prev = NULL;
	   *stack = newNode;
   }
   else
   {
	   /*(*stack)->prev = newNode;*/
	   /*newNode->n = c_fetch;*/
	   newNode->prev = NULL;
	   newNode->next = *stack;
	   *stack = newNode;
   }
   /*free(newNode);*/
}

/**
 * c_pall - prints all the values on the stack
 * @stack: double linked list
 * @line_number: line number of opcode
 */
void c_pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
    stack_t *print;

	print = *stack;

	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}

/**
 * c_pint - prints the value at the top of the stack
 * @stack: double linked list
 * @line_number: line number of opcode
 */
void c_pint(stack_t **stack, unsigned int line_number)
{
    stack_t *print_tos;

	print_tos = *stack;
	if (stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (print_tos != NULL)
	{
	    printf("%d\n", print_tos->n);
	    print_tos = print_tos->next;
	}
	else
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * c_pop - removes the top element of the stack.
 * @stack: double linked list
 * @line_number: line number of opcode
 */
void c_pop(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        printf("L%d: can't pop an empty stack", line_number);
        exit(EXIT_FAILURE);
    }
    delete_dnodeint_at_index(stack, 0);
}

/**
 * c_nop - doesn’t do anything.
 * @stack: double linked list
 * @line_number: line number of opcode
 */
void c_nop(__attribute__ ((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	return;
}
