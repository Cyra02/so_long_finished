/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:54:17 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/08 10:55:26 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_sstrlen(const char *str)
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
