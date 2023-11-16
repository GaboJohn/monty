#include "monty.h"

/**
 * opcode_pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	pop = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(pop);
}
