/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:10:02 by fionni            #+#    #+#             */
/*   Updated: 2025/09/27 16:10:03 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_top_nodes(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
	return (1);
}

void	sa(t_stack_node **a)
{
	if (!swap_top_nodes(a))
		return ;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b)
{
	if (!swap_top_nodes(b))
		return ;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap_top_nodes(a);
	swap_top_nodes(b);
	ft_putstr_fd("ss\n", 1);
}
