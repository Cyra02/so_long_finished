/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfombra <alfombra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:23:14 by ciestrad          #+#    #+#             */
/*   Updated: 2024/04/10 20:26:14 by alfombra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"
#include <stdio.h>

char	*ft_get_line(int fd, char *b)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(b, '\n') && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free (buff);
			free (b);
			return (NULL);
		}
		buff[bytes] = '\0';
		b = join(b, buff);
	}
	free (buff);
	return (b);
}

char	*create_line(char *b)
{
	int		i;
	char	*str;

	i = 0;
	if (!b[i])
		return (NULL);
	while (b[i] && b[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (b[i] && b[i] != '\n')
	{
		str[i] = b[i];
		i++;
	}
	if (b[i] == '\n')
	{
		str[i] = b[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *b)
{
	int		i;
	int		j;
	char	*buff2;

	i = 0;
	while (b[i] && b[i] != '\n')
		i++;
	if (!b[i])
	{
		free(b);
		return (NULL);
	}
	buff2 = (char *)malloc(sizeof(char) * (ft_strlen(b) - i + 1));
	if (!buff2)
		return (free(buff2), NULL);
	i++;
	j = 0;
	while (b[i])
		buff2[j++] = b[i++];
	buff2[j] = '\0';
	free(b);
	return (buff2);
}

char	*get_next_line(int fd)
{
	static char		*linea;
	char			*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	linea = ft_get_line(fd, linea);
	if (!linea)
		return (NULL);
	next = create_line(linea);
	linea = new_line(linea);
	return (next);
}

// int main ()
// {
//     int fd;

//     fd = open("ejemplo.txt", O_RDONLY );
//     printf("contenido %d",fd);
//     return(0);
// }

// #include <stdio.h>
// int main(void)
// {
//     int     fd;
//     char    *line;
//     fd = open("texto_prueba2.txt", O_RDONLY);
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }
