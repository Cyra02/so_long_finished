/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:53:00 by ciestrad          #+#    #+#             */
/*   Updated: 2024/05/02 15:32:39 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

static int	horizontal(t_complete *game)
{
	int	i;
	int	j;

	i = game->heightmap;
	j = 0;
	while (j < game->widthmap)
	{
		if (game->map[0][j] != '1' || game->map[i - 1][j] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

static int	vertical(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	check_elements(t_complete *game, int hi, int wid)
{
	if (game->map[hi][wid] != '1' &&
		game->map[hi][wid] != 'P' &&
		game->map[hi][wid] != 'E' &&
		game->map[hi][wid] != 'C' &&
		game->map[hi][wid] != '0' &&
		game->map[hi][wid] != '\n')
	{
		ft_printf("ERROR\nInvalid character->%c<-", game->map[hi][wid]);
		exit_game(game);
	}
	if (game->map[hi][wid] == 'C')
		game->coleccionables++;
	if (game->map[hi][wid] == 'P')
		game->player++;
	if (game->map[hi][wid] == 'E')
		game->exit++;
}

void	check_player(t_complete *game)
{
	int	hi;
	int	wid;

	hi = 0;
	while (hi < game->heightmap - 1)
	{
		wid = 0;
		while (wid <= game->widthmap)
		{
			check_elements(game, hi, wid);
			wid++;
		}
		hi++;
	}
	if (game->coleccionables < 1 \
		|| game->player != 1 \
		|| game->exit != 1)
	{
		ft_printf("ERROR\nThere are no collectibles");
		exit_game(game);
	}
}

void	check_errors(t_complete *game)
{
	int	i;

	i = 0;
	check_player(game);
	floop_fill(game);
	if (!vertical(game) || !horizontal(game))
	{
		ft_printf("ERROR\nThere are no walls");
		exit_game(game);
	}
	while (game->map[i])
	{
		if ((game->map[i][game->widthmap - 1] != '1')
			|| (game->map[i][game->widthmap] != '\n'
			&& game->map[i][game->widthmap] != '\0'))
		{
			ft_printf("ERROR\nIs not a perfect square");
			exit_game(game);
		}
		i++;
	}
}
