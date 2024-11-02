#include "push_swap.h"

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
	write(1, "pb\n", 3);
}

void push_to_a(t_node **head_b, t_node **tail_b, t_node **head_a, t_node **tail_a)
{
    (void)tail_b; // Игнорируем параметр
    if (*head_b == NULL)
        return; // Если список B пуст, ничего не делаем

    t_node *node_to_move = *head_b; // Узел, который нужно переместить
    *head_b = node_to_move->next; // Обновляем голову стека B
    if (*head_b)
        (*head_b)->prev = NULL; // Если новый head не NULL, обнуляем его prev

    // Обновляем указатели для перемещения в стек A
    node_to_move->next = *head_a; // Перемещаем указатель next перемещаемого узла на текущую голову стека A
    node_to_move->prev = NULL; // Обнуляем указатель prev перемещаемого узла

    if (*head_a == NULL) // Если A пуст
    {
        *head_a = node_to_move; 
        *tail_a = node_to_move; 
        node_to_move->next = NULL; // Для первого элемента next должен быть NULL
    }
    else // Если A не пуст
    {
        (*head_a)->prev = node_to_move; // Обновляем prev текущей головы стека A
        *head_a = node_to_move; // Теперь перемещаемый узел - это новая голова стека A
    }
    write(1, "pa\n", 3);
}
