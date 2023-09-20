#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;

	while (current)
	{
		stack_t *temp = current;
		current = current->next;
		free(temp);
	}
}
