/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:29:49 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/10 17:38:03 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void static	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = s;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = malloc(count * size);
	if (i == NULL)
		return (NULL);
	ft_bzero(i, count * size);
	return (i);
}
