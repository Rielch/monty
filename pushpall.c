#include "monty.h"

/**
 * push - push an element to the stack
 *
 * @head: head of the stack
 * @line: actual line
 * @n: integer argument
 * Return: void
 */

void push(stack_t **head, unsigned int line, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head->prev = new;
	*head = new;
}


/**
 * pall - prints all values on the stack
 *
 * @head: head of the stack
 * @line: actual line
