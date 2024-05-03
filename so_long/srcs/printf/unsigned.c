/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:31:59 by ciestrad          #+#    #+#             */
/*   Updated: 2023/10/17 13:25:04 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	getdigits(unsigned int param)
{
	int	digits;

	digits = 1;
	while (param > 9)
	{
		param /= 10;
		digits++;
	}
	return (digits);
}

int	get_unsigned(unsigned int param)
{
	int			aux;

	aux = -1;
	if (param == 0)
		write (1, "0", 1);
	else
	{
		if (param > 2147483647)
		{
			aux = param % 10;
			param /= 10;
		}
		ft_putnbr_fd(param, 1);
		if (aux >= 0)
			ft_putchar_fd(aux + 48, 1);
	}
	if (aux == -1)
	{
		return (getdigits(param));
	}
	return (getdigits(param) + 1);
}

/*int main(void)
{
	get_unsigned(2147483647 + 2147483648);
	return (0);
}*/