#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if(!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

char	**join_and_split(int argc, char **argv)
{
	char	*joined;
	char	**tokens;

	joined = join_args(argc, argv);
	if (!joined)
		return (NULL);
	tokens = ft_split(joined, ' ');
	free(joined);
	return (tokens);
}

int has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr [i] == arr [j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_split(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ps_puterr(const char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}
