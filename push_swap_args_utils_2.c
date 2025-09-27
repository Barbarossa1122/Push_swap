/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_args_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:09:51 by fionni            #+#    #+#             */
/*   Updated: 2025/09/27 16:16:48 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_sign_state(const char *s, int *sign, int *i)
{
	if (!s || !*s)
		return (0);
	*i = 0;
	*sign = 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	return (s[*i] != '\0');
}

static int	accumulate_digit(long *res, char c, int sign)
{
	if (c < '0' || c > '9')
		return (0);
	*res = *res * 10 + (c - '0');
	if ((sign == 1 && *res > (long)INT_MAX)
		|| (sign == -1 && - *res < (long)INT_MIN))
		return (0);
	return (1);
}

int	safe_atoi(const char *s, int *out)
{
	long	res;
	int		sign;
	int		i;

	if (!out || !init_sign_state(s, &sign, &i))
		return (0);
	res = 0;
	while (s[i])
	{
		if (!accumulate_digit(&res, s[i], sign))
			return (0);
		i++;
	}
	*out = (int)(res * sign);
	return (1);
}

static char	*append_with_free(char *acc, const char *suffix)
{
	char	*tmp;

	if (!acc)
		return (NULL);
	tmp = ft_strjoin(acc, suffix);
	free(acc);
	return (tmp);
}

char	*join_args(int argc, char **argv)
{
	char	*acc;
	int		i;

	if (argc <= 1)
		return (NULL);
	acc = ft_strdup("");
	if (!acc)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		acc = append_with_free(acc, argv[i]);
		if (!acc)
			return (NULL);
		if (i < argc - 1)
		{
			acc = append_with_free(acc, " ");
			if (!acc)
				return (NULL);
		}
		i++;
	}
	return (acc);
}
