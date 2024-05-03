/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:29:54 by ciestrad          #+#    #+#             */
/*   Updated: 2023/10/17 12:33:06 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	get_string(char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
