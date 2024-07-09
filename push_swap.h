/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:45:15 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/09 17:17:56 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

// Check and Parse Arguments
int		check_arguments(char **argv);
int		validate_number(const char *str);
int		check_multiple_numbers(const char *arg);
int		check_single_number(const char *arg);

// Utils
void	ft_error(char *str);
void	ft_free(char **str);
int     stack_is_empty(t_list **stack);
void	free_stack(t_list **stack);
void    print_stack(t_list **stack);
void    free_stack_and_exit(t_list **stack, char *msg);

// Initialize Stack
int		initialize_stack(char **argv, t_list **stack_a);
int		check_duplicates(t_list *stack);
int		check_stack_order(t_list **stack);

// Stack Instruction
int		swap(t_list **stack);
int		swap_stack_a(t_list **stack_a);
int		swap_stack_b(t_list **stack_b);
int		swap_both_stack(t_list **stack_a, t_list **stack_b);

int		push(t_list **dest_stack, t_list **src_stack);
int		push_stack_a(t_list **stack_a, t_list **stack_b);
int		push_stack_b(t_list **stack_a, t_list **stack_b);

int		rotate_stack(t_list **stack);
int		rotate_stack_a(t_list **stack_a);
int		rotate_stack_b(t_list **stack_b);
int		rotate_both_stack(t_list **stack_a, t_list **stack_b);

int		reverse_rotate_stack(t_list **stack);
int		reverse_rotate_stack_a(t_list **stack_a);
int		reverse_rotate_stack_b(t_list **stack_b);
int		reverse_rotate_both_stack(t_list **stack_a, t_list **stack_b);

// Sort Algorithms
void	small_sort(t_list **stack_a, t_list **stack_b);
void	sort_3_number(t_list **stack_a);
void	sort_4_number(t_list **stack_a, t_list **stack_b);
void	sort_5_number(t_list **stack_a, t_list **stack_b);

void	move_element_to_top(t_list **stack_a, int postion);
int		min_element_postion(t_list **stack_a);

int		*sorted_stack_in_tab(t_list **stack_a, int stack_size);
int		*bubble_sort(int *tab, int size);
int		max_element_postion(t_list *stack_a);
void	big_sort(t_list **stack_a, t_list **stack_b);
void	push_back_to_stack_a(t_list **stack_a, t_list **stack_b);

int     reverse_sorted_percentage(t_list *stack);
void    optimized_big_sort(t_list **stack_a, t_list **stack_b);

#endif