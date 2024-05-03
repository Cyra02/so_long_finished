/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:14:54 by ciestrad          #+#    #+#             */
/*   Updated: 2024/05/02 15:36:28 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "ft_printf.h"

static int	check_width(char *matriz)
{
	int	width;

	width = 0;
	if (!matriz)
		return (0);
	while (matriz[width] != '\0')
		width++;
	if (matriz[width -1] == '\n')
		width--;
	return (width);
}

static int	get_line(t_complete *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
	{
		return (0);
	}
	i = 0;
	game->heightmap++;
	temp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temp[game->heightmap] = NULL;
	while (game->heightmap -1 > i)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	map_reading(t_complete *game, char **argv)
{
	char	*line;
	int		paco;

	paco = 0;
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return ((void)ft_printf("ERROR\nMap does not exits \n"), 0);
	while (1)
	{
		line = get_next_line(game->fd);
		if (!get_line(game, line))
		{
			break ;
		}
	}
	close(game->fd);
	if (game->map == NULL)
		return ((void)ft_printf("ERROR\nThe file is empty\n"), 0);
	game->widthmap = check_width(game->map[0]);
	return (1);
}
