#include "monty.h"

/**
 * opcode_swap - Swaps the top two elements
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *swap;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	swap = (*stack)->next;
	(*stack)->next = swap->next;

	if (swap->next != NULL)
	{
		swap->next->prev = *stack;
	}
	swap->prev = NULL;
	swap->next = *stack;
	(*stack)->prev = swap;
	*stack = swap;
}
