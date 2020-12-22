#include "monty.h"

int arg = 0;

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
		dprintf(2, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	fstat(fd, &st);
	size = st.st_size;
	text = malloc(sizeof(char) * size);
	if (text == NULL)
	{
		dprintf(2, "Error: malloc failed");
		close(fd);
		exit(EXIT_FAILURE);
	}
	read(fd, text, size);
	for (a = 0; text[a] != '\0'; a++)
	{
		if (text[a] == '\n')
		{
			ln++;
		}
	}
	lines = malloc(sizeof(char *) * (ln + 1));
	if (lines == NULL)
	{
		dprintf(2, "Error: malloc failed");
		free(lines);
		close(fd);
		exit(EXIT_FAILURE);
	}
	temp = strtok(text, "\n");
	lines[0] = temp;
	for (a = 1; a < ln; a++)
	{
		temp = strtok(NULL, "\n");
		lines[a] = temp;
	}
	lines[a] = NULL;
	close(fd);
	return (lines);
}

/**
 * rdline - reads te command from the line
 *
 * @line: line to read
 * Return: comand and argument
 */

char *rdline(char *line, unsigned int ln, stack_t **head)
{
	char *command, *num;
	int a;

	command = strtok(line, " ");
	if (strcmp(command, "push") != 0)
	{
		arg = 0;
	}
	else
	{
		num = strtok(NULL, " ");
		if (num == NULL)
		{
			dprintf(2, "L%d: usage: push integer", ln);
			exit(EXIT_FAILURE);
		}
		for (a = 0; num[a] != '\0'; a++)
		{
			if (num[a] < '0' || num[a] > '9')
			{
				dprintf(2, "L%d: usage: push integer", ln);
				freestack(head);
				exit(EXIT_FAILURE);
			}
		}
		arg = atoi(num);
	}
	return (command);
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
	char **lines, *command;
	stack_t *head = NULL;
	unsigned int idx, a;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"", NULL},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	lines = readin(argv[1]);
	for (idx = 0; lines[idx] != NULL; idx++)
	{
		command = rdline(lines[idx], idx + 1, &head);
		for (a = 0; instruction[a].opcode != NULL; a++)
		{
			if (strcmp(command, instruction[a].opcode) == 0)
			{
				instruction[a].f(&head, idx + 1);
				break;
			}
		}
		if (instruction[a].opcode == NULL)
		{
	dprintf(2, "L%d: unknown instruction %s\n", idx + 1, command);
	freetext(lines);
	freestack(&head);
	exit(EXIT_FAILURE);
		}
	}
	return (0);
}
