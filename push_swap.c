/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:10:28 by fionni            #+#    #+#             */
/*   Updated: 2025/09/27 16:20:11 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	build_stack(int argc, char **argv, t_stack_node **a)
{
	int	*values;
	int	count;

	values = NULL;
	count = parse_input(argc, argv, &values);
	if (count == -1)
	{
		free(values);
		ps_puterr("Error\n");
		return (-1);
	}
	if (!ps_build_stack_a(a, values, count))
	{
		free(values);
		ps_puterr("Error\n");
		return (-1);
	}
	free(values);
	return (count);
}

static void	sort_stack(t_stack_node **a, t_stack_node **b, int count)
{
	if (is_sorted(*a))
		return ;
	if (count == 2)
		sort_2(a);
	else if (count == 3)
		sort_3(a);
	else if (count == 4)
		sort_4(a, b);
	else if (count == 5)
		sort_5(a, b);
	else
	{
		assign_index(*a);
		radix_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				count;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	count = build_stack(argc, argv, &a);
	if (count == -1)
		return (1);
	sort_stack(&a, &b, count);
	ps_stack_clear(&a);
	ps_stack_clear(&b);
	return (0);
}
