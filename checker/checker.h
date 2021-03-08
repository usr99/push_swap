/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:27:22 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/08 23:10:14 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

t_list	*get_stack(char **argv);
int		is_integer(char *str, int **nb);
int		is_duplicate(t_list *stack, int value);
void	*destroy_lst(t_list **lst);

t_list	*read_instructions(void);
int		is_instruction(char *str);

void	sort_stack(t_list *a, t_list *instructions);
void	do_sort(char *instruction, t_list **a, t_list **b);
void	do_swap(char stack, t_list **a, t_list **b);
void	do_rotate(char stack, t_list **a, t_list **b);
void	do_rev_rotate(char stack, t_list **a, t_list **b);

void	swap(t_list **stack);
void	push(t_list **a, t_list **b);
void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
int		is_sorted(t_list *a);

#endif
