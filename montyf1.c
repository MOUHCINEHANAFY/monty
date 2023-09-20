#include "monty.h"

/**
 * pall - prints the stack
 * @head: pointer to the head of the stack
 * @counter: not used
 * Return: no return
 */
void pall(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;

    (void)counter;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * push - add node to the stack
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: no return
 */
void push(stack_t **head, unsigned int counter)
{
    int n = 0, j = 0;

    if (!montyf.arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(montyf.file);
        free(montyf.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (montyf.arg[0] == '-')
    {
        j++;
    }

    while (montyf.arg[j] != '\0')
    {
        if (montyf.arg[j] < '0' || montyf.arg[j] > '9')
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(montyf.file);
            free(montyf.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
        n = (n * 10) + (montyf.arg[j] - '0');
        j++;
    }

    if (montyf.lifi == 0)
    {
        addnode(head, n);
    }
    else
    {
        addqueue(head, n);
    }
}

/**
 * pint - pint function
 * @head: stack head
 * @counter: line number
 */
void pint(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}
/**
 * pop - removes the top element from the stack
 * @head: stack head
 * @counter: line_number
 */
void pop(stack_t **head, unsigned int counter)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(montyf.file);
		/* free content */

		free(montyf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	free(tmp);
}
