/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:33:22 by ciestrad          #+#    #+#             */
/*   Updated: 2024/05/02 13:35:31 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	move(t_complete *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		game->count++;
		ft_printf("Steps: %i \n", game->count);
		if (game->coleccionables == 0)
			exit_game(game);
		else
		{
			game->map[y][x] = 'I';
			game->x_axis = x;
			game->y_axis = y;
			game->count++;
		}
	}
	if (game->map[y][x] == 'C' || game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->count++;
	}
	if (game->map[y][x] == 'C')
		game->coleccionables--;
	return (1);
}

void	fill(char **map, t_pos size, t_pos cur, char charfill)
{
	if (((cur.y_pos < 0 || cur.y_pos > size.y_pos)
			|| (cur.x_pos < 0 || cur.x_pos > size.x_pos))
		|| map[cur.y_pos][cur.x_pos] == '1'
		|| map[cur.y_pos][cur.x_pos] == charfill)
		return ;
	map[cur.y_pos][cur.x_pos] = 'P';
	fill(map, size, (t_pos){cur.x_pos - 1, cur.y_pos}, charfill);
	fill(map, size, (t_pos){cur.x_pos + 1, cur.y_pos}, charfill);
	fill(map, size, (t_pos){cur.x_pos, cur.y_pos - 1}, charfill);
	fill(map, size, (t_pos){cur.x_pos, cur.y_pos + 1}, charfill);
}

static t_pos	find(char **map, char player)
{
	t_pos	position;
	int		x;
	int		y;

	position.x_pos = -1;
	position.y_pos = -1;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == player)
			{
				position.x_pos = x;
				position.y_pos = y;
				return (position);
			}
			x++;
		}
		y++;
	}
	return (position);
}

void	floop_fill(t_complete *game)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)malloc(sizeof(game->map[i]) * (game->heightmap +1));
	while (i < game->heightmap)
	{
		temp[i] = ft_sstrdup(game->map[i]);
		i++;
	}
	temp[i] = NULL;
	game->playerpos = find(game->map, 'P');
	temp[game->playerpos.y_pos][game->playerpos.x_pos] = '0';
	fill(temp, (t_pos){game->widthmap - 1,
		game->heightmap - 1}, game->playerpos, 'P');
	if (find(temp, 'C').x_pos != -1 || find(temp, 'E').x_pos != -1)
	{
		ft_printf("ERROR\nInvalid map");
		exit_game(game);
	}
}
