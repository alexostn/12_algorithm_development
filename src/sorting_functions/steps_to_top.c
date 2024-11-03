#include "push_swap.h"

int calculate_steps_to_top(t_node *head_b, int target_index)
{
    int len = 0;
    t_node *current = head_b;

    // Считаем длину стека
    while (current != NULL)
    {
        len++;
        current = current->next;
    }

    // Если целевой индекс меньше половины длины, используем rotate_b
    if (target_index < len / 2)
    {
        return target_index; // Количество шагов для rotate_b
    }
    else
    {
        return len - target_index; // Количество шагов для reverse_rotate_b
    }
}
