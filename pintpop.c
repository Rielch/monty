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

/**
 * swap - swaps the top two elements of the stack
 *
 * @head: head of the stack
 * @line: line number
 * Return: void
 */

void swap(stack_t **head, unsigned int line)
{
	stack_t *temp = *head, *temp2;

	if (*head == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	temp->next = temp2->next;
	temp->prev = temp2;
	temp2->prev = NULL;
	temp2->next = temp;
	*head = temp2;
}

/**
 * addm - add the top two elements of the stack
 *
 * @head: head of the stack
 * @line: line number
 * Return: void
 */

void addm(stack_t **head, unsigned int line)
{
	stack_t *temp = *head, *temp2;

	if (*head == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	temp2->n = temp->n + temp2->n;
	temp2->prev = NULL;
	free(temp);
	*head = temp2;
}
