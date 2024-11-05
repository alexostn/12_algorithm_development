#include "push_swap.h"

// Define a function that handles the case when stack `a` contains three nodes and sorts it
void sort_three(t_node **head_a, t_node **tail_a)
{
    t_node *biggest_node; // Pointer to the largest node in stack `a`

    biggest_node = find_max(*head_a); // Find the largest node
    if (biggest_node == *head_a) // Check if the current node is the largest
        rotate_a(head_a, tail_a); // If so, rotate the top node to the bottom
    else if ((*head_a)->next == biggest_node) // Check if the second node is the largest
        reverse_rotate_a(head_a, tail_a); // If so, rotate the bottom node to the top

    // Check if the top node is greater than the second node
    if ((*head_a)->value > (*head_a)->next->value)
        sa(head_a); // If so, simply swap the top and the second nodes
}
