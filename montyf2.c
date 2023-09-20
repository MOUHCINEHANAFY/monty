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
