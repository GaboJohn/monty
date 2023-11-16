#include "monty.h"

/**
 * add_que - push node to tail stack
 * @stack: pointer to stack
 * @n: new value
 * Return: none
 */
void add_que(stack_t **stack, int n)
{
	stack_t *tmp, *node;

	tmp = *stack;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error\n");
		return;
	}
	node->n = n;
	node->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		tmp->next = node;
		node->prev = tmp;
	}
}
