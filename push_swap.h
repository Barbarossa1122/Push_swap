/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:17:38 by fionni            #+#    #+#             */
/*   Updated: 2025/09/27 16:22:56 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					final_index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

t_stack_node	*ps_node_new(int value);
void			ps_add_back(t_stack_node **stack, t_stack_node *new);
int				ps_stack_size(t_stack_node *stack);
int				ps_build_stack_a(t_stack_node **a, int *vals, int n);
void			ps_stack_clear(t_stack_node **s);
int				is_number(char *str);
int				safe_atoi(const char *s, int *out);
char			*join_args(int argc, char **argv);
char			**join_and_split(int argc, char **argv);
void			free_split(char **tab);
int				has_duplicates(int *arr, int n);
int				parse_input(int argc, char **argv, int **out_values);
void			ps_puterr(const char *s);
int				assign_index(t_stack_node *a);
int				is_sorted(t_stack_node *a);
void			sort_2(t_stack_node **a);
void			sort_3(t_stack_node **a);
void			sort_4(t_stack_node **a, t_stack_node **b);
void			sort_5(t_stack_node **a, t_stack_node **b);
void			radix_sort(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif
