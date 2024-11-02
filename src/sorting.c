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

// Moves elements from list A to list B until only three remain in A
void move_until_three(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
	while (count_nodes(*head_a) > 3) // Continue until there are 3 or fewer nodes in A
	{
		push_to_b(head_a, tail_a, head_b, tail_b); // Move the top element from A to B
	}
	// Переместите один элемент из B обратно в A
	if (*head_b) // Проверяем, есть ли что перемещать
	{
		push_to_a(head_b, tail_b, head_a, tail_a); // Move the top element from B to A
	}
	// Вызовите функцию rotate_a после перемещения элемента
	rotate_a(head_a, tail_a); // Поворачиваем стек A
	rotate_b(head_b, tail_b);
	rotate_rr(head_a, tail_a, head_b, tail_b);

	reverse_rotate_a(head_a, tail_a);
	reverse_rotate_b(head_b, tail_b);
	reverse_rotate_rr(head_a, tail_a, head_b, tail_b);

	sa(head_a);
	sb(head_b);
	ss(head_a, head_b);
}


