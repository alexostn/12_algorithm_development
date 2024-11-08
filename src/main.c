#include "push_swap.h"

// Function to print the list and the closest smaller value for each node
void print_list(t_node *head, const char *list_name)
{
    t_node *current = head;
    int index = 0; // Начинаем индексацию с 0

    ft_putstr_fd(list_name, 1);
    ft_putstr_fd(":\n", 1);
    while (current)
    {
        // Печатаем информацию о значении узла и ближайшем большем значении
        printf("Node %d: Value = %d, Closest Bigger Node = %d\n", 
               index++, 
               current->value, 
               current->closest_bigger);
        current = current->next;
    }
    ft_putstr_fd("\n", 1);
}


int count_elements(t_node *head)
{
    int count = 0;
    t_node *current = head;

    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        t_node *head_a = NULL;
        t_node *tail_a = NULL;
        t_node *head_b = NULL;
        t_node *tail_b = NULL;

        for (int i = 1; i < ac; i++)
        {
            ft_split_and_convert(av[i], &head_a, &tail_a);
        }

        if (is_list_sorted(head_a))
        {
            ft_putstr_fd("List is already sorted\n", 1); // Delete this line after!!!
            free_list(head_a);
            return (0);
        }

        // Проверяем количество элементов в списке A
        int element_count = count_elements(head_a);
		if (element_count == 2) // sa для двух элементов
		{
			sa(&head_a);
            free_list(head_a);
            free_list(head_b);
            return (0); // Завершаем программу после сортировки
		}
        if (element_count == 3)
        {
            sort_three(&head_a, &tail_a); // Вызов функции сортировки для трёх элементов
            ft_putstr_fd("List A sorted with sort_three\n", 1); // Сообщение о выполнении сортировки
            free_list(head_a);
            free_list(head_b);
            return (0); // Завершаем программу после сортировки
        }

        if (!is_list_sorted(head_a))
        {
            move_until_three(&head_a, &tail_a, &head_b, &tail_b);//1 STEP
			sort_three(&head_a, &tail_a);						//2 STEP
            // find_closest_smaller(head_a, head_b);
			find_closest_bigger(head_a, head_b);				//3 STEP
			calculate_total_steps_for_b_to_a(head_a, head_b);
            // Print lists A and B after the operation
            print_list(head_a, "List A");
            print_list(head_b, "List B");

            free_list(head_a);
            free_list(head_b);
        }
    }
    return (0);
}
