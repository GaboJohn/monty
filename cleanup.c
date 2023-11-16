#include "monty.h"

/**
 * cleanup - free memory used by stack
 * @stack: double pointer to stack
 */
void cleanup(stack_t **stack)
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
