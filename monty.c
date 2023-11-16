#include "monty.h"

miss_t mission = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for the Monty Interpreter
 *
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	FILE *txt;
	char *info;
	stack_t *stack = NULL;
	unsigned int line_num;
	ssize_t t = 1;
	size_t x = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: error\n");
		exit(EXIT_FAILURE);
	}
	txt = fopen(argv[1], "r");
	mission.txt = txt;
	if (!txt)
	{
		fprintf(stderr, "Error %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (t > 0)
	{
		info = NULL;
		t = getline(&info, &x, txt);
		mission.info = info;
		line_num++;
		if (t > 0)
		{
			execute(&stack, info, txt, line_num);
		}
		free(info);
	}
	cleanup(&stack);
	fclose(txt);

	return (0);
}
