/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:05:46 by ciestrad          #+#    #+#             */
/*   Updated: 2023/10/18 11:48:54 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
		}
		if (n / 10 == 0)
		{
			num = n + '0';
			write(fd, &num, 1);
		}
		else
		{
			num = n % 10 + '0';
			ft_putnbr_fd (n / 10, fd);
			write (fd, &num, 1);
		}
	}
}
