/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:27:15 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/27 19:40:23 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

t_list	*get_stack(char **argv);
int		is_integer(char *str, int **nb);
int		is_duplicate(t_list *stack, int value);
void	*destroy_lst(t_list **lst);

t_list	*get_stack_from_file(char **argv);
t_list	*read_file(int fd);

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
