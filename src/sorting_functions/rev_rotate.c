#include "push_swap.h"

// Reverse rotates the stack A by moving the last element to the top
void reverse_rotate_a(t_node **head_a, t_node **tail_a)
{
	if (*head_a == NULL || (*head_a)->next == NULL)
		return; // If list A is empty or has only one element, do nothing

	t_node *last_node = *tail_a; // Save the current tail
	*tail_a = last_node->prev; // Update the tail to the previous node
	if (*tail_a) // Ensure tail is not NULL before accessing
		(*tail_a)->next = NULL; // Set the next of the new tail to NULL

	// Move the last node to the front
	last_node->next = *head_a; // Link the last node to the current head
	last_node->prev = NULL; // Set the previous pointer of the last node to NULL
	if (*head_a) // Ensure head is not NULL before accessing
		(*head_a)->prev = last_node; // Set the previous pointer of the current head to the last node
	*head_a = last_node; // Update the head to the last node

	write(1, "rra\n", 4); // Output the operation
}

// Reverse rotates the stack B by moving the last element to the top
void reverse_rotate_b(t_node **head_b, t_node **tail_b)
{
	if (*head_b == NULL || (*head_b)->next == NULL)
		return; // If list B is empty or has only one element, do nothing

	t_node *last_node = *tail_b; // Save the current tail
	*tail_b = last_node->prev; // Update the tail to the previous node
	if (*tail_b) // Ensure tail is not NULL before accessing
		(*tail_b)->next = NULL; // Set the next of the new tail to NULL

	// Move the last node to the front
	last_node->next = *head_b; // Link the last node to the current head
	last_node->prev = NULL; // Set the previous pointer of the last node to NULL
	if (*head_b) // Ensure head is not NULL before accessing
		(*head_b)->prev = last_node; // Set the previous pointer of the current head to the last node
	*head_b = last_node; // Update the head to the last node

	write(1, "rrb\n", 4); // Output the operation
}

// Reverse rotates both stack A and stack B by moving the last elements to the tops
void reverse_rotate_rr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
	reverse_rotate_a(head_a, tail_a); // Call reverse rotate for stack A
	reverse_rotate_b(head_b, tail_b); // Call reverse rotate for stack B
	write(1, "rrr\n", 4); // Output the operation
}
