#include "monty.h"

/**
 * mod - calculates the remainder of the division
 * @head: stack head
 * @counter: line number
 */
void mod(stack_t **head, unsigned int counter)
{
	int result;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
	fclose(montyf.file);
	/* free content */
	free(montyf.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", counter);
	fclose(montyf.file);
	/* free content */
	free(montyf.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	result = (*head)->next->n % (*head)->n;
	(*head)->next->n = result;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
/**
 * pchar - prints character stack top
 * @head: stack head
 * @counter: line number
 */
void pchar(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	temp = *head;
	if (!temp)
	{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
	fclose(montyf.file);
	/* free content */
	free(montyf.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
	fclose(montyf.file);
	/* free content */
	free(montyf.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	putchar(temp->n);
	putchar('\n');
}
/**
 * pstr - prints the string top of the stack,
 * @head: stack head
 * @counter: line number
 */
void pstr(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	(void)counter;

	temp = *head;
	if (!temp)
	{
	fclose(montyf.file);
	/* free content */
	free(montyf.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	while (temp && temp->n > 0 && temp->n <= 127)
	{
	putchar(temp->n);
	temp = temp->next;
	}
	putchar('\n');
}
