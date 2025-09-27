/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:10:08 by fionni            #+#    #+#             */
/*   Updated: 2025/09/27 16:10:09 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*new_head;
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	new_head = first->next;
	new_head->prev = NULL;
	first->next = NULL;
	last = new_head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	*stack = new_head;
	return (1);
}

void	ra(t_stack_node **a)
{
	if (!rotate_stack(a))
		return ;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **b)
{
	if (!rotate_stack(b))
		return ;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putstr_fd("rr\n", 1);
}
