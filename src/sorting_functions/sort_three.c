#include "push_swap.h"

// Функция для сортировки трех элементов в стеке A
void sort_three(t_node **head_a)
{
    if (is_list_sorted(*head_a))
        return; // Если список уже отсортирован, ничего не делаем

    int first = (*head_a)->value;
    int second = (*head_a)->next->value;
    int third = (*head_a)->next->next->value;

    if (first > second && second < third && first < third)
        sa(head_a); // Сначала меняем местами первые два элемента

    if (first > second && second < third && first > third)
    {
        sa(head_a);
        reverse_rotate_a(head_a, NULL); // Перемещаем последний элемент в начало
    }

    if (first > second && second > third)
        rotate_a(head_a, NULL); // Сортируем в порядке третьего, второго, первого

    if (first < second && second > third && first < third)
        reverse_rotate_a(head_a, NULL); // Перемещаем первый элемент в конец

    if (first < second && second > third && first > third)
    {
        sa(head_a);
        rotate_a(head_a, NULL); // Сортируем в порядке первого, третьего, второго
    }
}
