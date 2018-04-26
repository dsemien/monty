#include "monty.h"

/**
 *
 *
 *
 *
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

void file_open(char *file_name, stack_t **stack)
{
	char *buff = NULL;
	char *new;
	size_t t = 0;
	int count = 0;;
	int c_test, line;
	instruct instruct;

	FILE *file = fopen(file_name, "r");
	if(file == NULL)
	{
		printf("Error: Cant opend file\n");
		exit(EXIT_FAILURE);
	}
	while((line = getline(&buff, &t, file)) != -1)
	{
		new = line_tok(buff);
		if (new == NULL || new[0] == '#')
		{
			count++;
			continue;
		}
		instruct = op_func(new);
		if(instruct == NULL)
		{
			printf("Error: Couldn't find correct function\n");
			exit(EXIT_FAILURE);
		}
		instruct(stack, count);
		count++;
	}
	free(new);
	c_test = fclose(file);
	if (c_test == -1)
		exit(-1);
	return;
}

instruct op_func(char *line)
{
	int x;
		
	instruction_t inst[] = {
		/*{"push", c_push},
		{"pall", c_pall},
		{"pint", c_pint},
		{"pop", c_pop},
		{"swap", c_swap},
		{"add", c_add},*/
		{"nop", c_nop},
		{NULL, NULL},
	};
	x = 0;

	while(inst[x].f != NULL && strcmp(inst[x].opcode, line) != 0)
		x++;

	return (inst[x].f);
}

char *line_tok(char *str)
{
	char *line;
	
	line = strtok(str, "\n ");
	if (line == NULL)
		return (NULL);
	return (line);
}
