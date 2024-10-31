#include "push_swap.h"

// Checks if the list is sorted
int is_list_sorted(t_node *head)
{
	t_node *current = head;

	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0); // Not in order
		current = current->next;
	}
	return (1); // Order maintained
}

// Moves the top element from list A to B
void push_to_b(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
	(void)tail_a; // Ignoring the parameter
	if (*head_a == NULL)
		return; // If list A is empty, do nothing

	t_node *node_to_move = *head_a;
	*head_a = node_to_move->next; 
	if (*head_a)
		(*head_a)->prev = NULL;

	if (*head_b == NULL) // If B is empty
	{
		*head_b = node_to_move; 
		*tail_b = node_to_move;
		node_to_move->next = NULL;
		node_to_move->prev = NULL;
	}
	else // If B is not empty
	{
		(*tail_b)->next = node_to_move; 
		node_to_move->prev = *tail_b;
		node_to_move->next = NULL;
		*tail_b = node_to_move; 
	}
}

// Helper function to count the number of nodes in a list
int count_nodes(t_node *head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}

// Moves elements from list A to list B until only three remain in A
void move_until_three(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
	while (count_nodes(*head_a) > 3) // Continue until there are 3 or fewer nodes in A
	{
		push_to_b(head_a, tail_a, head_b, tail_b); // Move the top element from A to B
	}
}

