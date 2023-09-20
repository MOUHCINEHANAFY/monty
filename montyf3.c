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
