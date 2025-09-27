/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:10:25 by fionni            #+#    #+#             */
/*   Updated: 2025/09/27 16:10:25 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ps_node_new(int value)
{
	t_stack_node	*n;

	n = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!n)
		return (NULL);
	n->nbr = value;
	n->index = -1;
	n->final_index = -1;
	n->push_cost = 0;
	n->above_median = false;
	n->cheapest = false;
	n->target = NULL;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

void	ps_add_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

int	ps_stack_size(t_stack_node *stack)
{
	int				count;
	t_stack_node	*cur;

	count = 0;
	cur = stack;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

int	ps_build_stack_a(t_stack_node **a, int *vals, int n)
{
	int				i;
	t_stack_node	*new;
	t_stack_node	*tmp;

	if (!a || !vals || n < 0)
		return (0);
	i = 0;
	while (i < n)
	{
		new = ps_node_new(vals[i]);
		if (!new)
		{
			while (*a)
			{
				tmp = (*a)->next;
				free(*a);
				*a = tmp;
			}
			*a = NULL;
			return (0);
		}
		ps_add_back(a, new);
		i++;
	}
	return (1);
}

void	ps_stack_clear(t_stack_node **s)
{
	t_stack_node	*cur;
	t_stack_node	*next;

	if (!s || !*s)
		return ;
	cur = *s;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*s = NULL;
}
