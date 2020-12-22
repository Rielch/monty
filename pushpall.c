#include "monty.h"

int arg = 0;

/**
 * push - push an element to the stack
 *
 * @head: head of the stack
 * @line: actual line
 * Return: void
 */

void push(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *new, *temp = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = arg;
	new->next = temp;
	new->prev = NULL;
	if (temp != NULL)
	{
		temp->prev = new;
	}
	*head = new;
}


/**
 * pall - prints all values on the stack
 *
 * @head: head of the stack
 * @line: actual line
 * Return: void
 */

void pall(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *temp = *head;

	if (*head != NULL)
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

/**
 * freestack - frees the stack
 *
 * @head: head of the stack
 * Return: void
 */

void freestack(stack_t **head)
{
	stack_t *temp = *head, *temp2;

	if (*head != NULL)
	{
		while (temp != NULL)
		{
			temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
	}
}
