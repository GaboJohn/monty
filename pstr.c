#include "monty.h"

/**
 * opcode_pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;

	while (tmp)
	{
		if (tmp->n > 127 || tmp->n <= 0)
		{
			break;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
