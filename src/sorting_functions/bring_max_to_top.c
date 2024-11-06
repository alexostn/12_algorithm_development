#include "push_swap.h"

// Функция для нахождения максимального значения и подъема его на вершину стека B
void bring_max_to_top(t_node **head_b, t_node **tail_b)
{
	if (!head_b || !(*head_b) || !(*head_b)->next)
		return; // Если стек пуст или содержит только один элемент, ничего не делаем

	t_node *current = *head_b;
	t_node *max_node = *head_b;
	int max_index = 0;
	int current_index = 0;
	int total_nodes = count_nodes(*head_b);

	// Поиск узла с максимальным значением и его индекса
	while (current)
	{
		if (current->value > max_node->value)
		{
			max_node = current;
			max_index = current_index;
		}
		current = current->next;
		current_index++;
	}

	// Определение, какой способ подъема использовать: rotate_b или reverse_rotate_b
	if (max_index <= total_nodes / 2)
	{
		// Используем rotate_b, если max_node ближе к началу стека
		while (*head_b != max_node)
		{
			rotate_b(head_b, tail_b);
		}
	}
	else
	{
		// Используем reverse_rotate_b, если max_node ближе к концу стека
		while (*head_b != max_node)
		{
			reverse_rotate_b(head_b, tail_b);
		}
	}
}
