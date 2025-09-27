/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:10:22 by fionni            #+#    #+#             */
/*   Updated: 2025/09/27 16:13:24 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack_node *a, int n)
{
	int				i;
	int				*arr;
	t_stack_node	*cur;

	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (NULL);
	cur = a;
	i = 0;
	while (i < n && cur)
	{
		arr[i] = cur->nbr;
		cur = cur->next;
		i++;
	}
	if (i != n)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

static int	*dup_array(const int *src, int n)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * n);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}

static void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_indices(t_stack_node *a, int *sorted, int n)
{
	int				i;
	t_stack_node	*cur;

	cur = a;
	while (cur)
	{
		i = 0;
		while (i < n)
		{
			if (sorted[i] == cur->nbr)
			{
				cur->index = i;
				break ;
			}
			i++;
		}
		cur = cur->next;
	}
}

int	assign_index(t_stack_node *a)
{
	int		n;
	int		*arr;
	int		*sorted;

	n = ps_stack_size(a);
	if (n <= 1)
		return (1);
	arr = stack_to_array(a, n);
	if (!arr)
		return (0);
	sorted = dup_array(arr, n);
	if (!sorted)
		return (free(arr), 0);
	bubble_sort(sorted, n);
	assign_indices(a, sorted, n);
	free(arr);
	free(sorted);
	return (1);
}
