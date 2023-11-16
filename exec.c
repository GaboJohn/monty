#include "monty.h"

/**
 * execute - execute opcode
 * @stack: linked list
 * @info: file information
 * @txt: pointer to file
 * @line_number: line number
 * Return: nothing
 */
int execute(stack_t **stack, char *info, FILE *txt, unsigned int line_number)
{
	instruction_t codeop[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{"sub", opcode_sub},
		{"div", opcode_div},
		{"mul", opcode_mul},
		{"mod", opcode_mod}
		
	};

		unsigned int x = 0;
		char *node;

		node = strtok(info, " \n\t");
		if (node && node[0] == '#')
			return (0);

		mission.args = strtok(NULL, " \n\t");

		while (codeop[x].opcode && node)
		{
			if (strcmp(node, codeop[x].opcode) == 0)
			{
				codeop[x].f(stack, line_number);
				return (0);
			}
			x++;
		}
		if (node && codeop[x].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, node);
			fclose(txt);
			free(info);
			cleanup(stack);
			exit(EXIT_FAILURE);
		}
		return (1);
}
