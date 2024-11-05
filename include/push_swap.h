#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
    struct s_node *prev;
    int closest_smaller; // Новый параметр для хранения наибольшего меньшего значения
	int total_steps;
} t_node;

// Parsing functions
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(const char *s, int fd);
int	ft_isdigit(int c);
int	is_within_int_range(char *arg);
int	is_numeric_argument(char *arg);
int	ft_atoi(const char *str);
char *ft_strcpy(char *s1, char *s2, int ammount);
t_node *create_node(int value);
void add_value_to_list(t_node **head_a, t_node **tail_a, int value);
void ft_split_and_convert(char *str, t_node **head_a, t_node **tail_a);
void free_list(t_node *head_a);

// Sorting functions
int is_list_sorted(t_node *head);
int count_nodes(t_node *head);

//Steps calculation
int calculate_steps_to_top(t_node *head, int target_index);
void calculate_total_steps_for_a(t_node *head_a, t_node *head_b);
int find_min_steps_node(t_node *head_a);

//Sort_three
t_node *find_max(t_node *head);
void sort_three(t_node **head_a, t_node **tail_a);
void move_until_three(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b);

void push_to_b(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b);
void push_to_a(t_node **head_b, t_node **tail_b, t_node **head_a, t_node **tail_a);

void rotate_a(t_node **head_a, t_node **tail_a);
void rotate_b(t_node **head_b, t_node **tail_b);
void rotate_rr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b);

void reverse_rotate_a(t_node **head_a, t_node **tail_a);
void reverse_rotate_b(t_node **head_b, t_node **tail_b);
void reverse_rotate_rr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b);

void sa(t_node **head_a);
void sb(t_node **head_b);
void ss(t_node **head_a, t_node **head_b);

//LOGICAL SORTING FUNCTIONS
// Функция для поиска наиболее близкого меньшего значения
void find_closest_smaller(t_node *head_a, t_node *head_b);

#endif