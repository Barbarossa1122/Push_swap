#include "push_swap.h"

int	is_sorted(t_stack_node *a)
{
	t_stack_node	*cur;

	if (!a || !a->next)
		return (1);
	cur = a;
	while (cur->next)
	{
		if (cur->nbr > cur->next->nbr)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	sort_2(t_stack_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_3(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->nbr;
	second = (*a)->next->nbr;
	third = (*a)->next->next->nbr;
	if (first > second && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && first > third)
		rra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
}
