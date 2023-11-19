#include "monty.h"

/**
 * opcode_stack - Sets the format of the data to a stack (LIFO).
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mission.y = 0;
}

/**
 * opcode_queue - Sets the format of the data to a queue (FIFO).
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script.
 */
void opcode_queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	mission.y = 1;
}
