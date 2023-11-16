#include "monty.h"

/**
 * opcode_mul - Multiplies elements
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *num;
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	num = *stack;
	tmp = num->next->n * num->n;
	num->next->n = tmp;
	opcode_pop(stack, line_number);
}
