#include "push_swap.h"

// Sorts a stack with exactly 3 elements in descending order
void sort_three_descending(t_node **head_b, t_node **tail_b)
{
	t_node *first = *head_b;
	t_node *second = first->next;
	t_node *third = second->next;

	// Case 1: First is the largest
	if (first->value > second->value && first->value > third->value)
	{
		if (second->value < third->value)
		{
			// Second is the smallest: rotate_b to put third on top
			rotate_b(head_b, tail_b);
		}
		else
		{
			// Third is the smallest: swap_b to correct order
			sb(head_b);
		}
	}
	// Case 2: Second is the largest
	else if (second->value > first->value && second->value > third->value)
	{
		if (first->value < third->value)
		{
			// First is the smallest: reverse rotate to bring second to the top
			reverse_rotate_b(head_b, tail_b);
		}
		else
		{
			// Third is the smallest: swap_b then rotate_b to bring second on top
			sb(head_b);
			rotate_b(head_b, tail_b);
		}
	}
	// Case 3: Third is the largest
	else if (third->value > first->value && third->value > second->value)
	{
		// Third is already at the bottom, just swap the first two
		sb(head_b);
	}
}
