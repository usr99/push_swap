/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:27:22 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/15 16:05:10 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef struct	s_stack
{
	t_list	*a;
	t_list	*b;
	t_list	*algorithm;
}				t_stack;

int				push_swap(t_stack *stack);
int				sort_small(t_stack *stack);
int				sort_medium(t_stack *stack);
int				sort_big(t_stack *stack);

int				get_quartile_value(t_list *a, int *quartile, int size, int div);
int				push_sub_values(t_stack *stack, int quartile, int size);
int				repush_sub_values(t_stack *stack);
int				check_b(t_stack *stack, int value, int rb);
int				rotate_optimization(t_stack *stack, int ra, int rb);

int				add_instructions(t_stack *stack, char *instruction, int x);
void			ascending_sort(t_list *lst);
int				find_smallest(t_list *a);
int				find_largest(t_list *a);
int				find_inferior(t_list *a, int value);

int				sort_stack_size3(t_stack *stack);
int				push_a(t_stack *stack, int size, int pos);
int				push_b(t_stack *stack, int size, int pos);
void			optimize_ra(t_list **lst, int *ra);
int				optimize_rb(t_list *lst, int *rb);

#endif
