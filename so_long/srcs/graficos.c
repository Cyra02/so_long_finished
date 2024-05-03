/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graficos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:29:32 by ciestrad          #+#    #+#             */
/*   Updated: 2024/05/02 15:35:45 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_pointer,
		game->window, game->player1, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_pointer,
		game->window, game->colec, width * 40, height * 40);
	game->coleccionables++;
}

void	place_textures(t_complete *game)
{
	int	i;
	int	j;

	game->suelo = mlx_xpm_file_to_image(game->mlx_pointer,
			"imagenes/floor.xpm", &i, &j);
	game->pared = mlx_xpm_file_to_image(game->mlx_pointer,
			"imagenes/pared.xpm", &i, &j);
	game->player1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"imagenes/player.xpm", &i, &j);
	game->salida = mlx_xpm_file_to_image(game->mlx_pointer,
			"imagenes/exit.xpm", &i, &j);
	game->colec = mlx_xpm_file_to_image(game->mlx_pointer,
			"imagenes/coleccionable.xpm", &i, &j);
	game->salida_player = mlx_xpm_file_to_image(game->mlx_pointer,
			"imagenes/salida_player.xpm", &i, &j);
}

void	place_graphics(t_complete *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->pared, width * 40, height * 40);
	if (game->map[height][width] == 'C')
		place_collectable(game, height, width);
	if (game->map[height][width] == 'P')
	{
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->suelo, width * 40, height * 40);
		place_player(game, height, width);
	}
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->salida, width * 40, height * 40);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->suelo, width * 40, height * 40);
	if (game->map[height][width] == 'I')
		mlx_put_image_to_window(game->mlx_pointer,
			game->window, game->salida_player, width * 40, height * 40);
}

void	add_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->coleccionables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			place_graphics(game, height, width);
			width++;
		}
		height++;
	}
}
