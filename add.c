#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: pointer to the head of the stack
 * @n: new_value
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head)
	{
	(*head)->prev = new_node;
	}

	*head = new_node;
}

/**
 * addqueue - add node to the tail stack
 * @head: pointer to the head of the stack
 * @n: new_value
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL)
	{
	*head = new_node;
	}
	else
	{
	stack_t *tail = *head;

	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = new_node;
	new_node->prev = tail;
	}
}
