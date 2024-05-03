/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:39:01 by ciestrad          #+#    #+#             */
/*   Updated: 2023/10/17 16:23:01 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	hex_len(unsigned long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0)
	{
		len ++;
		num = num / 16;
	}
	return (len);
}

void	hexadecimal(unsigned int num, const char param)
{
	if (num >= 16)
	{
		hexadecimal((num / 16), param);
		hexadecimal((num % 16), param);
	}
	else
	{
		if (num <= 9)
			get_char((num + '0'));
		else
		{
			if (param == 'x')
				get_char ((num - 10 + 'a'));
			else if (param == 'X')
				get_char((num - 10 + 'A'));
		}
	}
}

int	get_hexadecimal( unsigned int num, const char param)
{
	if (num == 0)
		write (1, "0", 1);
	else
		hexadecimal(num, param);
	return (hex_len(num));
}
