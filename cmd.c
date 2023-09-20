#include "monty.h"

/**
 * cmd - executes the opcode from the content
 * @content: line content
 * @stack: stack head
 * @counter: line_number
 * @file: pointer to monty file
 * Return: 0 if successful, 1 if error
 */
int cmd(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	unsigned int i = 0;

	instruction_t opst[] = {
	{"push", push}, {"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap}, {"add", add},
	{"nop", nop}, {"sub", sub}, {"div", division},
	{"mul", multiplication}, {NULL, NULL}
	};

	char *op = strtok(content, " \n\t");

	if (!op || op[0] == '#')
	{
	return (0);
	}

	montyf.arg = strtok(NULL, " \n\t");

	while (opst[i].opcode)
	{
	if (strcmp(op, opst[i].opcode) == 0)
	{
	opst[i].f(stack, counter);
	return (0);
	}
	i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);

	return (1);
}
