#include "push_swap.h"

static int	count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

static int	fill_values(char **tokens, int *vals, int count)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < count)
	{
		if (!is_number(tokens[i]) || !safe_atoi(tokens[i], &tmp))
			return (0);
		vals[i] = tmp;
		i++;
	}
	return (1);
}

static int	alloc_and_fill(char **tokens, int count, int **vals_out)
{
	int	*vals;

	vals = (int *)malloc(sizeof(int) * count);
	if (!vals)
		return (0);
	if (!fill_values(tokens, vals, count))
	{
		free(vals);
		return (0);
	}
	*vals_out = vals;
	return (1);
}

int	parse_input(int argc, char **argv, int **out_values)
{
	char	**tokens;
	int		count;
	int		*vals;
	if (!out_values)
		return (-1);
	*out_values = NULL;
	tokens = join_and_split(argc, argv);
	if (!tokens)
		return (0);
	count = count_tokens(tokens);
	if (!alloc_and_fill(tokens, count, &vals))
		return (free_split(tokens), -1);
	free_split(tokens);
	if (has_duplicates(vals, count))
		return (free(vals), -1);
	*out_values = vals;
	return (count);
}
