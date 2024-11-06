#include "push_swap.h"

// Функция для вычисления количества шагов, необходимых для перемещения целевого узла на вершину указанного стека
int calculate_steps_to_top(t_node *head, int target_index)
{
    int len = 0;
    t_node *current = head;

    // Подсчет длины стека
    while (current != NULL)
    {
        len++;
        current = current->next;
    }

    // Если целевой индекс меньше половины длины, используем rotate
    if (target_index < len / 2)
    {
        return target_index; // Количество шагов для rotate
    }
    else
    {
        return len - target_index; // Количество шагов для reverse rotate
    }
}

// Функция для вычисления общего количества шагов для каждого узла в A с учетом B
void calculate_total_steps_for_a(t_node *head_a, t_node *head_b)
{
    t_node *current_a = head_a;
    int index_a = 0;

    while (current_a)
    {
        // Вычисление шагов для перемещения текущего узла в A на вершину
        int steps_a = calculate_steps_to_top(head_a, index_a);

        // Вычисление шагов для перемещения ближайшего меньшего узла в B на вершину
        int steps_b = calculate_steps_to_top(head_b, current_a->closest_smaller);

        // Вычисление общего количества шагов для текущего узла в A
        int total_steps = steps_a + steps_b;

        // Присвоение общего количества шагов узлу
        current_a->total_steps = total_steps; // Добавлено поле total_steps

        // Печать индекса и общего количества шагов для узлов в A
        // printf("Index: %d, Total Steps: %d\n", index_a, total_steps); // Печать индекса и общего количества шагов

        current_a = current_a->next;
        index_a++;
    }
}



// Функция для нахождения индекса узла в стеке A с минимальным общим количеством шагов
int find_min_steps_node(t_node *head_a)
{
    int min_steps = INT_MAX;
    int min_index = -1;
    int current_index = 0;

    t_node *current = head_a;
    while (current)
    {
        // printf("Index: %d, Total Steps: %d\n", current_index, current->total_steps); // Печать индекса и общего количества шагов

        if (current->total_steps < min_steps)
        {
            min_steps = current->total_steps;
            min_index = current_index;
        }
        current = current->next;
        current_index++;
    }

    // printf("First Minimum Index: %d\n", min_index); // Печать первого минимального индекса

    return min_index; // Возвращает индекс узла с минимальным общим количеством шагов
}

//////////////////////////////////////////////////////////////////////////////

// Функция для вычисления общего количества шагов для каждого узла в B с учетом A
void calculate_total_steps_for_b_to_a(t_node *head_a, t_node *head_b)
{
    t_node *current_b = head_b;
    int index_b = 0;

    printf("| Index B | Value B | Closest Bigger in A | Steps A | Steps B | Total Steps |\n");
    printf("|---------|---------|---------------------|---------|---------|-------------|\n");

    while (current_b)
    {
        // Вычисление шагов для перемещения ближайшего большего узла в A на вершину
        int steps_a = calculate_steps_to_top(head_a, current_b->closest_bigger); // Если у вас есть closest_bigger

        // Вычисление шагов для перемещения текущего узла в B на вершину
        int steps_b = calculate_steps_to_top(head_b, index_b);

        // Вычисление общего количества шагов для текущего узла в B
        int total_steps = steps_a + steps_b;

        // Присвоение общего количества шагов узлу
        current_b->total_steps = total_steps;

        // Печать результата для текущего узла
        printf("| %7d | %7d | %19d | %7d | %7d | %11d |\n", 
               index_b, current_b->value, current_b->closest_bigger, steps_a, steps_b, total_steps);

        current_b = current_b->next;
        index_b++;
    }
}


// #include "push_swap.h"

// // Calculate the number of steps to move the target node to the top of a specified stack
// int calculate_steps_to_top(t_node *head, int target_index)
// {
//     int len = 0;
//     t_node *current = head;

//     // Count the length of the stack
//     while (current != NULL)
//     {
//         len++;
//         current = current->next;
//     }

//     // If the target index is less than half of the length, use rotate
//     if (target_index < len / 2)
//     {
//         return target_index; // Number of steps for rotate
//     }
//     else
//     {
//         return len - target_index; // Number of steps for reverse rotate
//     }
// }

// // Function to calculate total steps for each node in A considering B
// void calculate_total_steps_for_a(t_node *head_a, t_node *head_b)
// {
//     t_node *current_a = head_a;
//     int index_a = 0;

//     while (current_a)
//     {
//         // Calculate steps to bring the current node in A to the top
//         int steps_a = calculate_steps_to_top(head_a, index_a);

//         // Calculate steps to bring the closest smaller node in B to the top
//         int steps_b = calculate_steps_to_top(head_b, current_a->closest_smaller);

//         // Calculate the total steps for the current node in A
//         int total_steps = steps_a + steps_b;

//         // Print the result for debugging
//         printf("Node index A: %d, Value: %d, Closest Smaller Index in B: %d, Steps A: %d, Steps B: %d, Total Steps: %d\n",
//                index_a, current_a->value, current_a->closest_smaller, steps_a, steps_b, total_steps);

//         current_a = current_a->next;
//         index_a++;
//     }
// }

// // Finds the index of the node in stack A with the minimum total steps
// int find_min_steps_node(t_node *head_a)
// {
// 	int min_steps = INT_MAX;
// 	int min_index = -1;
// 	int current_index = 0;

// 	t_node *current = head_a;
// 	while (current)
// 	{
// 		if (current->total_steps < min_steps)
// 		{
// 			min_steps = current->total_steps;
// 			min_index = current_index;
// 		}
// 		current = current->next;
// 		current_index++;
// 	}

// 	return min_index; // Return the index of the node with the minimum total steps
// }

// // int calculate_steps_to_top(t_node *head_b, int target_index)
// // {
// //     int len = 0;
// //     t_node *current = head_b;

// //     // Count the length of the stack
// //     while (current != NULL)
// //     {
// //         len++;
// //         current = current->next;
// //     }

// //     // If the target index is less than half of the length, use rotate_b
// //     if (target_index < len / 2)
// //     {
// //         return target_index; // Number of steps for rotate_b
// //     }
// //     else
// //     {
// //         return len - target_index; // Number of steps for reverse_rotate_b
// //     }
// // }
