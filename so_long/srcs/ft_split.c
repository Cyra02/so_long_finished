/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfombra <alfombra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:45:21 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/10 20:36:06 by alfombra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	num_words(const char *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i + 1] != c) && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

static void	freeall(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free (splits[i]);
		i++;
	}
	free (splits);
}

static size_t	checkmalloc(char **splits, int pos)
{
	if (splits[pos])
		return (1);
	freeall(splits);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**m;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	m = ft_calloc(num_words (s, c) + 1, sizeof(char *));
	if (!s || !m)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (j < i)
		{
			m[k++] = ft_substr(s, j, i - j);
			if (!checkmalloc(m, k - 1))
				return (0);
		}
	}
	return (m);
}

/*int main(void)
{
	char *a = "hola estoy cansada";
	char **c;

	c = ft_split(a, ' ');

	printf("%s\n", c[0]);
	printf("%s\n", c[1]);
	printf("%s", c[2]);
	return (0);
}*/