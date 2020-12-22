#include "monty.h"

/**
 * readin - read the input from the file
 *
 * @name: name of the file
 * Return: array of strings with opcodes and arguments
 */

char **readin(const char *name)
{
	int fd, a, ln = 0;
	char **lines, *text, *temp;
	unsigned int size;
	struct stat st;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		fprintf(2, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	fstat(fd, &st);
	size = st.st_size;
	text = malloc(sizeof(char) * size);
	if (text == NULL)
	{
		fprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	read(fd, &text, size);
	for (a = 0; text[a] != '\0'; a++)
	{
		if (text[a] == '\n')
		{
			ln++;
		}
	}
	lines = malloc(sizeof(char *) * ln);
	if (lines == NULL)
	{
		fprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	for (a = 0; a < ln; a++)
	{
		temp = strtok(text, "\n");
		lines[a] = temp;
	}
	close(fd);
	return (lines);
}

/**
 * main - reads and interprets monty code
 *
 * @argc: ammount of arguments
 * @argv: arguments given to the function
 * Return: 0 if complete
 */

int main(int argc, char **argv)
{
	char **lines;
	instruction_t inruction[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	if (argc != 2)
	{
		fprintf(2, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	lines = readin(argv[1]);
}
