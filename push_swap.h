/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:45:15 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/03 00:13:12 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

// typedef struct s_list
// {
// 	int value;
// 	struct s_list *next;
// 	int 	index;
// }	t_list;

// typedef struct s_list
// {
// 	int value;
// 	struct s_list *next;
// 	int 	index;
// }	t_list;

// Check and Parse Arguments
int		check_arguments(char **argv);
int		validate_number(const char *str);
int		check_multiple_numbers(const char *arg);
int		check_single_number(const char *arg);

// Utilis
void	ft_error(char *str);
void	ft_free(char **str);

// Initialize Stack
int		initialize_stack(char **argv, t_list **stack_a);
void	free_stack(t_list **stack);
int		check_duplicates(t_list *stack);
int		check_stack_order(t_list *stack);

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

#endif