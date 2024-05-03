/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:34:37 by ciestrad          #+#    #+#             */
/*   Updated: 2023/10/17 16:52:11 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	put_ptrhex(unsigned long int nb)
{
	if (nb >= 16)
	{
		put_ptrhex(nb / 16);
		put_ptrhex(nb % 16);
	}
	else
	{
		if (nb <= 9)
			get_char((nb + '0'));
		else
			get_char((nb - 10 + 'a'));
	}
}

int	get_adress(unsigned long int param)
{
	char	c;

	c = 0;
	c += write (1, "0x", 2);
	put_ptrhex(param);
	c += hex_len(param);
	return (c);
}
