#include "monty.h"

/**
* opcode_rotr - Rotates the stack to the bottom.
* @stack: Double pointer to the stack.
* @line_number: Line number in the script.
*/
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		*stack = tmp;
	}
}
