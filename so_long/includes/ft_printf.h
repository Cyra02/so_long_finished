/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfombra <alfombra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:58:33 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/10 20:20:24 by alfombra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int			get_char(char c);
int			get_num(int lst);
int			get_hexadecimal( unsigned int num, const char param);
int			get_string(char *s);
int			get_adress(unsigned long int param);
int			hex_len(unsigned long int num);
int			get_unsigned(unsigned int param);
int			ft_printf(char const *str, ...);
int			ft_len(int n);
int			ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);
#endif