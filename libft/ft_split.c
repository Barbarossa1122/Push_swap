/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:44:22 by fionni            #+#    #+#             */
/*   Updated: 2024/12/31 15:38:33 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_write_word(char *dest, char const *src, char c, int i)
{
	int	j;

	j = 0;
	while (src[i] && src[i] != c)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static char	**ft_split_part(char const *s, char c, char **m, int tot_words)
{
	int	i;
	int	i_matrix;
	int	len_word;

	i = 0;
	i_matrix = 0;
	while (i_matrix < tot_words)
	{
		len_word = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len_word++;
		}
		m[i_matrix] = (char *)malloc((len_word + 1) * (sizeof(char)));
		if (!m[i_matrix])
		{
			free_array(m, i_matrix);
			return (NULL);
		}
		ft_write_word(m[i_matrix], s, c, (i - (len_word)));
		len_word = 0;
		i_matrix++;
	}
	m[i_matrix] = NULL;
	return (m);
}

char	**ft_split(char const *s, char c)
{
	size_t	tot_words;
	char	**matrix;

	if (!s)
		return (0);
	tot_words = ft_count_words(s, c);
	matrix = (char **)malloc((tot_words + 1) * sizeof (char *));
	if (!matrix)
		return (NULL);
	matrix = ft_split_part(s, c, matrix, tot_words);
	return (matrix);
}

/*
int main(void)
{
    char *input = "hellocworldccvvvv";
    char **words = ft_split(input, 'c');
    int i = 0;

    while (words && words[i])
    {
        printf("word[%d]: %s\n", i, words[i]);
        i++;
    }
    return 0;
}
*/