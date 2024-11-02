#include "push_swap.h"

// Swaps the top two elements of stack A
void sa(t_node **head_a)
{
	if (*head_a == NULL || (*head_a)->next == NULL)
		return; // If list A is empty or has only one element, do nothing

	t_node *first = *head_a; // First element
	t_node *second = first->next; // Second element

	// Swap the elements
	first->next = second->next; // Link first to the third element (if it exists)
	if (first->next)
		first->next->prev = first; // Set the previous of the new second element
	second->next = first; // Link second to first
	second->prev = NULL; // Set second as the new head

	*head_a = second; // Update head to the new first element
	first->prev = second; // Set first as the second element
	write(1, "sa\n", 3); // Output the operation
}

// Swaps the top two elements of stack B
void sb(t_node **head_b)
{
	if (*head_b == NULL || (*head_b)->next == NULL)
		return; // If list B is empty or has only one element, do nothing

	t_node *first = *head_b; // First element
	t_node *second = first->next; // Second element

	// Swap the elements
	first->next = second->next; // Link first to the third element (if it exists)
	if (first->next)
		first->next->prev = first; // Set the previous of the new second element
	second->next = first; // Link second to first
	second->prev = NULL; // Set second as the new head

	*head_b = second; // Update head to the new first element
	first->prev = second; // Set first as the second element
	write(1, "sb\n", 3); // Output the operation
}

// Swaps the top two elements of both stacks A and B
void ss(t_node **head_a, t_node **head_b)
{
	sa(head_a); // Call sa for stack A
	sb(head_b); // Call sb for stack B
	write(1, "ss\n", 3); // Output the operation
}
