#include "monty.h"

/**
 * opcode_add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int x = 0, inn;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		x++;
	}
	if (x < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	inn = tmp->n + tmp->next->n;
	tmp->next->n = inn;
	*stack = tmp->next;
	free(tmp);
}
