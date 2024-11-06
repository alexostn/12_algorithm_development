#include "push_swap.h"

int get_node_value_by_index(t_node *head, int index)
{
    t_node *current = head;
    int current_index = 0;

    while (current)
    {
        if (current_index == index)
            return current->value;
        current = current->next;
        current_index++;
    }
    return -1; // Если индекс не найден
}

void find_closest_bigger(t_node *head_a, t_node *head_b)
{
    t_node *current_b = head_b;
    while (current_b)
    {
        int closest_bigger_value = INT_MAX; // Инициализация максимальным значением
        int index_a = 0; // Счетчик индекса узлов в A
        int best_index_a = -1; // Индекс узла с ближайшим большим значением
        int min_value = INT_MAX; // Минимальное значение в A
        int min_index = -1; // Индекс минимального значения A

        t_node *current_a = head_a;
        while (current_a)
        {
            // Поиск минимального значения и его индекса
            if (current_a->value < min_value)
            {
                min_value = current_a->value;
                min_index = index_a;
            }

            // Проверка условия для ближайшего большего значения
            if (current_a->value > current_b->value && current_a->value < closest_bigger_value)
            {
                closest_bigger_value = current_a->value;
                best_index_a = index_a;
            }
            current_a = current_a->next;
            index_a++;
        }

        // Если ближайшее большее значение не найдено, используем индекс минимального
        if (best_index_a == -1)
        {
            best_index_a = min_index;
        }

        current_b->closest_bigger = best_index_a; // Сохранение индекса узла A в узле B

        // Выводим информацию о найденном ближайшем большем значении для каждого узла B
        printf("Node B with value %d has closest bigger value from Node A with index %d (value = %d)\n",
               current_b->value,
               current_b->closest_bigger,
               (current_b->closest_bigger >= 0 ? get_node_value_by_index(head_a, current_b->closest_bigger) : -1));

        current_b = current_b->next;
    }
}
