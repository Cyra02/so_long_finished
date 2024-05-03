/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:36:14 by ciestrad          #+#    #+#             */
/*   Updated: 2024/05/02 13:35:23 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include "mlx.h"
#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *) b + i) = c;
		i++;
	}
	return (b);
}

int	exit_game(t_complete *game)
{
	int	line;

	line = 0;
	if (game->window)
		mlx_destroy_window(game->mlx_pointer, game->window);
	free(game->mlx_pointer);
	while (line <= game->heightmap -1)
	{
		free(game->map[line++]);
	}
	free(game->map);
	ft_printf("\nFinished");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	if (!ft_strchr(argv[1], '.ber'))
	{
		ft_printf("ERROR\nNot type .ber file\n");
		exit (0);
	}
	ft_memset(&game, 0, sizeof(t_complete));
	init_complete(&game);
	if (map_reading(&game, argv) == 0)
		return (0);
	check_errors(&game);
	game.mlx_pointer = mlx_init();
	game.window = mlx_new_window(game.mlx_pointer, (game.widthmap * 40),
			(game.heightmap * 40), "so_long");
	place_textures(&game);
	add_graphics(&game);
	mlx_key_hook(game.window, player_controls, &game);
	mlx_hook(game.window, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_pointer);
	return (0);
}
