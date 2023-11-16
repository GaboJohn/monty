#include "monty.h"

/**
 * opcode_div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	stack_t *num;
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
	tmp = num->n / num->n;
	num->next->n = tmp;
	*stack = num->next;
	free(num);
}
