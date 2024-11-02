#include "push_swap.h"

// Rotates the stack A by moving the top element to the bottom
void rotate_a(t_node **head_a, t_node **tail_a)
{
	if (*head_a == NULL || (*head_a)->next == NULL)
		return; // If list A is empty or has only one element, do nothing

	t_node *first_node = *head_a; // Save the current head
	*head_a = first_node->next; // Update head to the second node
	(*head_a)->prev = NULL; // Set the prev of the new head to NULL

	// Move the first node to the end of the list
	first_node->next = NULL; // Set the next of the first node to NULL
	first_node->prev = *tail_a; // Set the prev of the first node to the current tail
	if (*tail_a != NULL)
	{
		(*tail_a)->next = first_node; // Link the current tail to the first node
	}
	*tail_a = first_node; // Update the tail to the first node
	write(1, "ra\n", 3); // Output the operation
}

// Rotates the stack B by moving the top element to the bottom
void rotate_b(t_node **head_b, t_node **tail_b)
{
	if (*head_b == NULL || (*head_b)->next == NULL)
		return; // If list A is empty or has only one element, do nothing

	t_node *first_node = *head_b; // Save the current head
	*head_b = first_node->next; // Update head to the second node
	(*head_b)->prev = NULL; // Set the prev of the new head to NULL

	// Move the first node to the end of the list
	first_node->next = NULL; // Set the next of the first node to NULL
	first_node->prev = *tail_b; // Set the prev of the first node to the current tail
	if (*tail_b != NULL)
	{
		(*tail_b)->next = first_node; // Link the current tail to the first node
	}
	*tail_b = first_node; // Update the tail to the first node
	write(1, "rb\n", 3); // Output the operation
}

// Rotates both stack A and stack B by moving the top elements to the bottoms
void rotate_rr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    rotate_a(head_a, tail_a); // Call rotate for stack A
    rotate_b(head_b, tail_b); // Call rotate for stack B
    write(1, "rr\n", 3); // Output the operation
}