/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfombra <alfombra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:53:29 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/10 20:28:11 by alfombra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*join(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	while (i++ < len1)
		res[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < len2)
		res[i - 1 + len1] = s2[i - 1];
	res[i - 1 + len1] = '\0';
	free((char *)s1);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*result;

	if (!s1)
		return (NULL);
	i = 0;
	len = (ft_strlen((char *)s1));
	result = malloc(len + 1 * sizeof(char));
	if (result == NULL)
	{
		free (result);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*m;

	if (!s)
		return (NULL);
	i = 0;
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(start + s) < len)
		len = ft_strlen(start + s);
	m = malloc(sizeof(char) * (len + 1));
	if (!m)
	{
		free(m);
		return (NULL);
	}
	while (i < len)
	{
		m[i] = s[start];
		start++;
		i++;
	}
	m[i] = '\0';
	free((char *)s);
	return (m);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char			*result;
// 	unsigned int	i;

// 	if (!s1)
// 		return (NULL);
// 	result = malloc((ft_strlen(s1) + 1) * sizeof(char));
// 	if (result == NULL)
// 	{
// 		free(result);
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		result[i] = s1[i];
// 		i++;
// 	}
// 	result[i] = '\0';
// 	return (result);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int	j;
// 	char			*result;
// 	unsigned int	len_s;

// 	if (!s)
// 		return (NULL);
// 	len_s = ft_strlen((char *)s);
// 	if (len == 0 || start >= len_s || len > (len_s - start))
// 		return (NULL);
// 	j = 0;
// 	result = (char *)malloc((len + 1) * sizeof(char));
// 	if (result == NULL)
// 	{
// 		free(result);
// 		return (NULL);
// 	}
// 	while (j < len)
// 	{
// 		result[j] = s[start];
// 		start++;
// 		j++;
// 	}
// 	result[j] = '\0';
// 	free((char *)s);
// 	return (result);
// }

// char	*join(char const *s1, char const *s2)
// {
// 	char			*res;
// 	unsigned int	i;
// 	unsigned int	len1;
// 	unsigned int	len2;

// 	i = 0;
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
// 	if (res == NULL)
// 	{
// 		free(res);
// 		return (NULL);
// 	}
// 	while (i++ < len1)
// 		res[i - 1] = s1[i - 1];
// 	i = 0;
// 	while (i++ < len2)
// 		res[i - 1 + len1] = s2[i - 1];
// 	res[i - 1 + len1] = '\0';
// 	free((char *)s1);
// 	return (res);
// }