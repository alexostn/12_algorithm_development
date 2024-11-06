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

// Function to find the index of the node with the closest smaller value

void find_closest_smaller(t_node *head_a, t_node *head_b)
{
	t_node *current_a = head_a;
	while (current_a)
	{
		int closest_smaller_value = INT_MIN; // Initialize with the smallest possible value
		int index_b = 0; // Index counter for nodes in B (starting from 0)
		int best_index_b = -1; // Index of the node in B with the closest smaller value
		int max_value = INT_MIN; // Maximum value in B
		int max_index = -1; // Index of the maximum value in B

		t_node *current_b = head_b;
		while (current_b)
		{
			// Find the maximum value and its index
			if (current_b->value > max_value)
			{
				max_value = current_b->value;
				max_index = index_b;
			}

			// Check condition for the closest smaller value
			if (current_b->value < current_a->value && current_b->value > closest_smaller_value)
			{
				closest_smaller_value = current_b->value; // Update the value
				best_index_b = index_b; // Save the index of node B
			}
			current_b = current_b->next;
			index_b++; // Increment the index for node B
		}

		// If no closest smaller value found, use the index of the maximum
		if (best_index_b == -1) 
		{
			best_index_b = max_index; // Use the index of the maximum
		}

		current_a->closest_smaller = best_index_b; // Save the index of node B in node A
		current_a = current_a->next;
	}
}

// Example usage in move_until_three function
void move_until_three(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
        if (count_nodes(*head_a) > 1)
        {
            // Переместить первый элемент в B
            push_to_b(head_a, tail_a, head_b, tail_b);
            // Переместить второй элемент в B
            push_to_b(head_a, tail_a, head_b, tail_b);
			bring_max_to_top(head_b, tail_b);
        }
    while (count_nodes(*head_a) > 3) // Продолжать, пока в A не останется три узла
    {
        find_closest_smaller(*head_a, *head_b);

        // Расчет и вывод общего количества шагов для каждого узла в A с учетом B
        calculate_total_steps_for_a(*head_a, *head_b);
        int min_steps_index = find_min_steps_node(*head_a);//here we find min sters node
        // printf("Node in stack A with the minimum total steps is at index: %d\n", min_steps_index);
        
        // Перемещение узла с минимальным количеством шагов в B
        t_node *current_a = *head_a;
        int current_index = 0;

       while (current_a && count_nodes(*head_a) > 3)
        {
            if (current_index == min_steps_index)
            {
			if (count_nodes(*head_b) == 3)
				sort_three_descending(head_b, tail_b);
			bring_max_to_top(head_b, tail_b);
                // Переместить узел с минимальными шагами в B
			push_to_b(head_a, tail_a, head_b, tail_b);
			// //ATEMPT TO SORT B BEFORE PUSH 4TH ELEMENT
			
			// break; // Выход из цикла после перемещения
            }
            current_a = current_a->next;
            current_index++;
        }
		if ((*head_b)->value < (*tail_b)->value)//ДОЛГООЖИДАЕМЫЙ ROTATE БЕЗ КОТОРОГО ВОЗМОЖНО ОБОЙТИСЬ
			rotate_b(head_b, tail_b);


        // break; // Выйти из цикла после перемещения и сравнения
    }
}


// // Moves elements from list A to list B until only three remain in A
// void move_until_three(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
// {
// 	while (count_nodes(*head_a) > 3) // Continue until only three nodes remain in A
// 	{
// 		if (count_nodes(*head_a) > 1) 
// 		{
// 			// Move the first element to B
// 			push_to_b(head_a, tail_a, head_b, tail_b);
// 			// Move the second element to B
// 			push_to_b(head_a, tail_a, head_b, tail_b);
// 		}
		
// 		find_closest_smaller(*head_a, *head_b);

// 		// Протестируем calculate_steps_to_top для каждого узла в A
// 		t_node *current_a = *head_a;
// 		while (current_a)
// 		{
// 			int steps = calculate_steps_to_top(*head_b, current_a->closest_smaller);
// 			printf("Node value: %d, Closest Smaller Index: %d, Steps to Top B only: %d\n", 
// 				current_a->value, current_a->closest_smaller, steps);
// 			current_a = current_a->next;
// 		}
		
// 		break; // Exit the loop after moving and comparing
// 	}
// }


// WRITING EXAMPLES HOW TO USE FUNCTIONS:
// // Move one element from B back to A
// if (*head_b) // Check if there's anything to move
// {
// 	push_to_a(head_b, tail_b, head_a, tail_a); // Move the top element from B to A
// }
// // Call rotate_a after moving an element
// rotate_a(head_a, tail_a); // Rotate stack A
// rotate_b(head_b, tail_b);
// rotate_rr(head_a, tail_a, head_b, tail_b);

// reverse_rotate_a(head_a, tail_a);
// reverse_rotate_b(head_b, tail_b);
// reverse_rotate_rr(head_a, tail_a, head_b, tail_b);

// sa(head_a);
// sb(head_b);
// ss(head_a, head_b);
