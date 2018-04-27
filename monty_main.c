#include "monty.h"
int c_fetch = 0;
/**
 * main - starts program to interp. monty file
 * @ac: argument count
 * @av: arguments
 * Return: 0 succesfull
 **/

int main(int ac, char **av)
{
	stack_t *new;

	new = NULL;
	if (ac != 2)
	{
		exit(-1);
	}
	file_open(av[1], &new);
	free(new);
	return (0);
}
/**
 * file_open - opens monty file and retrives data
 * @file_name: name of file with byte code
 * @stack: stack_t struct
 **/
void file_open(char *file_name, stack_t **stack)
{
	char *buff = NULL;
	int c_test, line;
	char *new;
	size_t t = 0;
	int count = 0;
	instruct instruct;

	FILE *file = fopen(file_name, "r");

	if (file == NULL)
	{
		printf("Error: Cant opend file\n");
		exit(EXIT_FAILURE);
	}
	while ((line = getline(&buff, &t, file)) != -1)
	{
		new = line_tok(buff);
		if (new == NULL || new[0] == '#')
		{
			count++;
			continue;
		}
		instruct = op_func(new);
		if (instruct == NULL)
		{
			printf("Error: Couldn't find correct function\n");
			exit(EXIT_FAILURE);
		}
		instruct(stack, count);
		count++;
	}
	free(new);
	free(buff);
	c_test = fclose(file);
	if (c_test == -1)
		exit(-1);
}
/**
 * op_func - gets correct func based of opcode
 * @line: argument to retrive function
 * Return: function based off argument
 **/
instruct op_func(char *line)
{
	int x;

	instruction_t inst[] = {
		{"push", c_push},
		{"pall", c_pall},
		/*
		 * {"pint", c_pint},
		 * {"pop", c_pop},
		 * {"swap", c_swap},
		 * {"add", c_add},
		 */
		{"nop", c_nop},
		{NULL, NULL},
	};
	x = 0;

	while (inst[x].f != NULL && strcmp(inst[x].opcode, line) != 0)
		x++;



	return (inst[x].f);
}
/**
 * line_tok - tokenizes userinput
 * @str: user input
 * Return: string
 **/
char *line_tok(char *str)
{
	char *line, *var, *push;

	push = "push";
	line = strtok(str, "\n ");
	if (line == NULL)
		return (NULL);
	if (strcmp(line, push) == 0)
	{
		var = strtok(NULL, "\n ");
		if (number(var) == 1 && var != NULL)
		{
			c_fetch = atoi(var);
		}
		else
		{
			printf("Error");
			free(var);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

/**
 * number - checks if string is number
 * @buff: user input
 * Return: 0 if ot digit
 **/
int number(char *buff)
{
	unsigned int x;

	if (buff == NULL)
		return (0);
	x = 0;
	while (buff[x])
	{
		if (buff[0] == '-')
		{
			x++;
			continue;
		}
		if (!isdigit(buff[x]))
			return (0);
		x++;
	}
	return (1);
}
