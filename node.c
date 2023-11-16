#include "monty.h"

/**
 * add_node - add node to stack
 * @stack: pointer to stack
 * @n: new value
 * Return: nothing
 */
void add_node(stack_t **stack, int n)
{
	stack_t *tmp, *node;

	tmp = *stack;
	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = node;
	node->n = n;
	node->next = *stack;
	node->prev = NULL;
	*stack = node;
}
