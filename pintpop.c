#include "monty.h"

/**
 * pint - print the value in the top of the stack
 *
 * @head: head of the stack
 * @line: line number
 * Return: void
 */

void pint(stack_t **head, unsigned int line)
{
	stack_t *temp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", temp->n);
	}
}

/**
 * pop - removes the top element of the stack
 *
 * @head: head of the stack
 * @line: line number
 * Return: void
 */

void pop(stack_t **head, unsigned int line)
{
	stack_t *temp = *head, *temp2;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	free(temp);
	if (temp2 != NULL)
	{
		temp2->prev = NULL;
	}
	*head = temp2;
}
