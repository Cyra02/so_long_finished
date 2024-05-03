/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:00:09 by ciestrad          #+#    #+#             */
/*   Updated: 2024/05/02 13:34:02 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

static int	keyboard_w(int direction, t_complete *game)
{
	int	x;
	int	y;
	int	i;

	x = game->x_axis;
	y = game->y_axis;
	if (direction == 13)
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		i = move(game, x, y);
		if (!i)
			return (0);
		if (game->map[y + 1][x] == 'I')
			game->map[y + 1][x] = 'E';
		else
			game->map[y + 1][x] = '0';
	}
	ft_printf("Steps: %i \n", game->count);
	return (1);
}

static int	keyboard_a(int direction, t_complete *game)
{
	int	x;
	int	y;
	int	i;

	x = game->x_axis;
	y = game->y_axis;
	if (direction == 0)
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		i = move(game, x, y);
		if (!i)
			return (0);
		if (game->map[y][x + 1] == 'I')
			game->map[y][x + 1] = 'E';
		else
			game->map[y][x + 1] = '0';
	}
	ft_printf("Steps: %i \n", game->count);
	return (1);
}

static int	keyboard_s(int direction, t_complete *game)
{
	int	x;
	int	y;
	int	i;

	x = game->x_axis;
	y = game->y_axis;
	if (direction == 1)
	{
		y++;
		if (game->map[y][x] == '1')
			return (0);
		i = move(game, x, y);
		if (!i)
			return (0);
		if (game->map[y - 1][x] == 'I')
			game->map[y - 1][x] = 'E';
		else
			game->map[y - 1][x] = '0';
	}
	ft_printf("Steps: %i \n", game->count);
	return (1);
}

static int	keyboard_d(int direction, t_complete *game)
{
	int	x;
	int	y;
	int	i;

	x = game->x_axis;
	y = game->y_axis;
	if (direction == 2)
	{
		x++;
		if (game->map[y][x] == '1')
			return (0);
		i = move(game, x, y);
		if (!i)
			return (0);
		if (game->map[y][x - 1] == 'I')
			game->map[y][x - 1] = 'E';
		else
			game->map[y][x - 1] = '0';
	}
	ft_printf("Steps: %i \n", game->count);
	return (1);
}

int	player_controls(int direction, t_complete *game)
{
	int	i;

	i = 0;
	if (direction == 53)
		exit_game(game);
	if (direction == 13)
		i = keyboard_w(direction, game);
	if (direction == 0)
		i = keyboard_a(direction, game);
	if (direction == 1)
		i = keyboard_s(direction, game);
	if (direction == 2)
		i = keyboard_d(direction, game);
	if (i)
	{
		add_graphics(game);
	}
	return (1);
}
