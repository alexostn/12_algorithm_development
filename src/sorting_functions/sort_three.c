#include "push_swap.h"

// Определяем функцию, которая обрабатывает случай, когда стек `a` содержит три узла, и сортирует его
void sort_three(t_node **head_a, t_node **tail_a)
{
    t_node *biggest_node; // Указатель на наибольший узел в стеке `a`

    biggest_node = find_max(*head_a); // Найти максимальный узел
    if (biggest_node == *head_a) // Проверяем, является ли текущий узел наибольшим
        rotate_a(head_a, tail_a); // Если да, вращаем верхний узел вниз
    else if ((*head_a)->next == biggest_node) // Проверяем, является ли второй узел наибольшим
        reverse_rotate_a(head_a, tail_a); // Если да, вращаем нижний узел вверх

    // Проверяем, если верхний узел больше второго узла
    if ((*head_a)->value > (*head_a)->next->value) 
        sa(head_a); // Если да, просто меняем местами верхний и второй узлы
}