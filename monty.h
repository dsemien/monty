#ifndef MP
#define MP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

extern int c_fetch;
int c_fetch = 0;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* FUNCTION DEFINTIONS */

typedef void (*instruct)(stack_t **stack, unsigned int count);
char *line_tok(char *str);
instruct op_func(char *line);
void file_open(char *file_name, stack_t **stack);
void c_nop(stack_t **stack, unsigned int count);
void c_push(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void c_pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void c_pint(stack_t **stack, unsigned int line_number);
void c_pop(stack_t **stack, unsigned int line_number);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
int number(char *buff);

/* END DEF'S */
#endif
