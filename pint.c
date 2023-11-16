#include "monty.h"

/**
 * opcode_pint - print the top
 * @stack: pointer to stack
 * @line_number: counter
 * Return: no return
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: cant't pint, stack empty\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
