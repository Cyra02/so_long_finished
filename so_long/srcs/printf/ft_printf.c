/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:34:30 by ciestrad          #+#    #+#             */
/*   Updated: 2023/10/18 11:43:24 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	num(char c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	get_type(char typ, va_list param)
{
	if (typ == 'c')
		return (get_char(va_arg(param, int)));
	else if (typ == 'i' || typ == 'd')
		return (get_num(va_arg(param, int)));
	else if (typ == 's')
		return (get_string(va_arg(param, char *)));
	else if (typ == 'p')
		return (get_adress(va_arg(param, uintptr_t)));
	else if (typ == 'x' || typ == 'X')
		return (get_hexadecimal(va_arg(param, int), (unsigned long int)typ));
	else if (typ == 'u')
		return (get_unsigned(va_arg(param, unsigned int)));
	else if (typ == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	lst;
	int		i;
	int		type;

	i = 0;
	type = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (type != -1)
				type += get_type (str[++i], lst);
		}
		else
			if (type != -1)
				type += num(str[i]);
		i++;
	}
	va_end(lst);
	return (type);
}

// int main(void)
// {
// 	char a = 'q';
// 	int b = 23;
// 	char c[] = "estrade";
// 	ft_printf("Hola %cue tal, tengo %i anos y me apellido %s\n", a, b, c);
// 	printf("%i = %i?\n", ft_printf("%x", 0), printf("%x", 0));
// 	ft_printf("%");
// 	return (0);
// }
