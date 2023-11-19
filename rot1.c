#include "monty.h"

/**
 * opcode_rotl - Rotates the stack to the top.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
