#include "monty.h"

/**
 * subm - substract the top two elements of the stack
 *
 * @head: head of the stack
 * @line: line number
 * Return: void
 */

void subm(stack_t **head, unsigned int line)
{
	stack_t *temp = *head, *temp2;

	if (*head == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	temp2->n = temp2->n - temp->n;
	temp2->prev = NULL;
	free(temp);
	*head = temp2;
}

/**
 * divm - divide the second top element of the stack by the top element
 *
 * @head: head of the stack
 * @line: line number
 * Return: void
 */

void divm(stack_t **head, unsigned int line)
{
	stack_t *temp = *head, *temp2;

	if (*head == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	temp2->n = temp2->n / temp->n;
	temp2->prev = NULL;
	free(temp);
	*head = temp2;
}

/**
 * mulm - multiplies the two top elements of the stack
 *
 * @head: head of the stack
 * @line: line number
 * Return: void
 */

void mulm(stack_t **head, unsigned int line)
{
	stack_t *temp = *head, *temp2;

	if (*head == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	temp2->n = temp2->n * temp->n;
	temp2->prev = NULL;
	free(temp);
	*head = temp2;
}

/**
 * modm - computes the rest of the division of the second element of the stack by the first
 *
 * @head: head of the stack
 * @line: line number
 * Return: void
 */

void modm(stack_t **head, unsigned int line)
{
	stack_t *temp = *head, *temp2;

	if (*head == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	temp2->n = temp2->n % temp->n;
	temp2->prev = NULL;
	free(temp);
	*head = temp2;
}

/**
 * pchar - prints the char at the top of the stack
 *
 * @head: head of the stack
 * @line: line number
 * Return: void
 */

void pchar(stack_t **head, unsigned int line)
{
	stack_t *temp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	putchar(temp->n);
}
