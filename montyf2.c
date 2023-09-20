#include "monty.h"

/**
 * add - adds the top 2 elements
 * @head: head of the stack
 * @counter: line number
 */
void add(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", counter);
	fclose(montyf.file);
	free(montyf.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	temp = *head;

	temp->next->n += temp->n;
	*head = temp->next;
	free(temp);
}

/**
 *nop - The function of nothing
 *@head: stack head
 *@counter: line number
 */
void nop(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fclose(montyf.file);
		/* free content */
		free(montyf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	(void) counter;
	(void) head;
}
/**
 * sub - subtracts the top element from the second top element of the stack
 * @head: stack head
 * @counter: line number
 */
void sub(stack_t **head, unsigned int counter)
{
	int result;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
	fclose(montyf.file);
	/* free content */
	free(montyf.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	result = (*head)->next->n - (*head)->n;
	(*head)->next->n = result;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
/**
 * division - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 */
void division(stack_t **head, unsigned int counter)
{
	int result;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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

	result = (*head)->next->n / (*head)->n;
	(*head)->next->n = result;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
/**
 * multiplication - multiplies top two elements
 * @head: stack head
 * @counter: line number
 */
void multiplication(stack_t **head, unsigned int counter)
{
	int result;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
	fclose(montyf.file);
	/* free content */
	free(montyf.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	result = (*head)->next->n * (*head)->n;
	(*head)->next->n = result;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
