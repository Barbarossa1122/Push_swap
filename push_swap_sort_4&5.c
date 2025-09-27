/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_4&5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:10:20 by fionni            #+#    #+#             */
/*   Updated: 2025/09/27 16:10:20 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack_node *a)
{
	int				pos;
	int				best_pos;
	int				best_val;
	t_stack_node	*cur;

	best_val = a->nbr;
	best_pos = 0;
	pos = 0;
	cur = a;
	while (cur)
	{
		if (cur->nbr < best_val)
		{
			best_val = cur->nbr;
			best_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (best_pos);
}

static void	rotate_to_top(t_stack_node **a, int pos)
{
	int	size;

	size = ps_stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
}

void	sort_4(t_stack_node **a, t_stack_node **b)
{
	int	pos;

	if (!a || !*a || ps_stack_size(*a) != 4)
		return ;
	pos = find_min_pos(*a);
	rotate_to_top(a, pos);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack_node **a, t_stack_node **b)
{
	int	pos;

	if (!a || !*a || ps_stack_size(*a) != 5)
		return ;
	pos = find_min_pos(*a);
	rotate_to_top(a, pos);
	pb(a, b);
	pos = find_min_pos(*a);
	rotate_to_top(a, pos);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
