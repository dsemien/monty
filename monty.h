#ifndef MP
#define MP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern int fetch;

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
void c_nop(__attribute__ ((unused))stack_t **stack, __attribute__ ((unused))unsigned int count);
void c_push(stack_t **stack, __ attribute__ ((unsused))unsigned int line_number);
void c_pall(stack_t **stack, __attribute__ ((unsused))unsigned int line_number);
void c_pint(stack_t **stack, unsigned int line_number);
void c_pop(stack_t **stack, unsigned int line_number);


/* END DEF'S */
#endif
