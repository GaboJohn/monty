#include "monty.h"

/**
 * opcode_sub - Subtracts the elements.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *num;
	int y;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	num = *stack;
	y = num->next->n - num->n;
	num->next->n = y;
	*stack = num->next;
	free(num);

}
