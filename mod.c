#include "monty.h"

/**
 * opcode_mod - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *num;
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	num = *stack;
	if (num->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	tmp = num->next->n % num->n;
	num->next->n = tmp;
	*stack = num->next;
	free(num);
}
