/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:59:42 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/10 17:42:34 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*m;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	m = malloc(sizeof(char) * ((ft_strlen(s1))
				+ (ft_strlen(s2)) + 1));
	if (!m)
		return (NULL);
	while (s1[i])
	{
		m[i + j] = s1[i];
		i++;
	}
	while (s2[j])
	{
		m[j + i] = s2[j];
		j++;
	}
	m[j + i] = '\0';
	return (m);
}
