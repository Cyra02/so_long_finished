/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:47:29 by ciestrad          #+#    #+#             */
/*   Updated: 2024/05/02 15:36:05 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_complete(t_complete *game)
{
	game->fd = 0;
	game->t_line = 0;
	game->widthmap = 0;
	game->widthmap = 0;
	game->coleccionables = 0;
	game->player = 0;
	game->exit = 0;
	game->x_axis = 0;
	game->y_axis = 0;
	game->count = 0;
	game->map_len = 0;
	game->map = NULL;
	game->mlx_pointer = 0;
	game->window = 0;
	game->colec = 0;
	game->suelo = 0;
	game->pared = 0;
	game->salida = 0;
	game->salida_player = 0;
	game->player1 = 0;
}

void	init_pos(t_pos *game)
{
	game->x_pos = 0;
	game->x_pos = 0;
}
