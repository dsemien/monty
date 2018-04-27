#include "monty.h"
/**
*
*
*
*
*/
void c_push(stack_t **stack, __attribute__ ((unsused))unsigned int line_number)
{
   stack_t *newNode;

   newNode = malloc(sizeof(stack_t));
   if (newNode == NULL)
   {
       printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
   }
   newNode->n = fetch;
   if (*stack == NULL)
      newNode->next = NULL;
      newNode->prev = NULL;
      *stack = newNode;
   else
    *(stack)->prev = newNode;
    newNode->n = fetch;
    newNode->next = *stack;
    newNode->prev = NULL;   
   *stack = newNode;
  
   printf("\nInsertion is Success\n");
}

/**
*
*
*
*
*/
void c_pall(stack_t **stack, __attribute__ ((unsused))unsigned int line_number)
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
*
*
*
*
*/
void c_pint(stack_t **stack, unsigned int line_number)
{
    stack_t *print_tos;

	print_tos = *stack;

	if (print_tos != NULL)
	    printf("%d\n", print_tos->n);
	else
        printf("L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
}

/**
*
*
*
*
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
*
*
*
*
*/
void c_nop(__attribute__ ((unused))stack_t **stack, __attribute__ ((unused))unsigned int count)
{
	printf("it works\n");
	return;
}
