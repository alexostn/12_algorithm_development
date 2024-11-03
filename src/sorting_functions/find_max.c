#include "push_swap.h"

// Function to find the node with the maximum value in the list
t_node *find_max(t_node *head)
{
    t_node *max_node = head;
    t_node *current = head;

    while (current)
    {
        if (current->value > max_node->value)
        {
            max_node = current;
        }
        current = current->next;
    }
    return max_node;
}