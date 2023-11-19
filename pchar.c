#include "monty.h"

/**
 * opcode_pchar - Print the character at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	if (tmp->n > 127 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}
