#include "monty.h"



/**
 * main - principal code interpreter
 * @argc: number of arguments
 * @argv: file position
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{   
	ssize_t read_line = 1;
	char *content;
	stack_t *stack = NULL;
	FILE *file;
	size_t size = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	global.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		global.content = content;
		line_number++;
		if (read_line > 0)
		{
			compile(content, &stack, line_number, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
