/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:45:15 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/02 16:56:03 by ouboukou         ###   ########.fr       */
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

int		check_arguments(char **argv);
int		validate_number(const char *str);
int		check_multiple_numbers(const char *arg);
int		check_single_number(const char *arg);

void	ft_error(char *str);
void	ft_free(char **str);

int		initialize_stack(char **argv, t_list **stack_a);
void	free_stack(t_list **stack);
int check_duplicates(t_list *stack);
int check_stack_order(t_list *stack);

#endif