#include "monty.h"

/**
 * opcode_push - add an element onto the stack
 * @stack: Double pointer to the stack
 * @line_number: where the push operation occurs
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	int y = 0, x = 0;
	int value;

	if (mission.args)
	{
		if (mission.args[0] == '-')
			x++;
		for (; mission.args[x] != '\0'; x++)
		{
			if (mission.args[x] > 57 || mission.args[x] < 48)
				y = 1;
		}
		if (y == 1)
		{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(mission.txt);
		free(mission.info);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(mission.args);
	if (mission.y == 0)
		add_node(stack, value);
	else
		add_que(stack, value);
}
/**
 * opcode_pall - Print all values on the stack
 * @stack: Double pointer to the stack
 * @line_number: counter
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	(void)line_number;

	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}
