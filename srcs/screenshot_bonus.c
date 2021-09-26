/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:43:51 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:21:56 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	write_header(int fd, int size, t_game game)
{
	unsigned char	header[54];
	size_t			i;

	i = 0;
	while (i < 54)
		header[i++] = 0;
	header[0] = 'B';
	header[1] = 'M';
	*((int*)(header + 2)) = size;
	header[10] = 54;
	header[14] = 40;
	*((int*)(header + 18)) = game.real_screen.width;
	*((int*)(header + 22)) = game.real_screen.height;
	header[26] = 1;
	header[28] = 24;
	*((int*)(header + 34)) = size - 54;
	write(fd, header, 54);
}

static int	get_color(int i, int j, t_game game)
{
	int		color;

	color = *((int*)(game.real_screen.data + 4 * j + game.real_screen.size_line
										* (game.real_screen.height - 1 - i)));
	return (color);
}

static void	write_content(int fd, int pad, t_game game)
{
	int					i;
	int					j;
	int					color;
	const unsigned char	zero[3] = {0, 0, 0};

	i = 0;
	while (i < game.real_screen.height)
	{
		j = 0;
		while (j < game.real_screen.width)
		{
			color = get_color(i, j, game);
			write(fd, &color, 3);
			j++;
		}
		if (pad > 0)
			write(fd, &zero, pad);
		i++;
	}
}

void		screenshot(t_game game)
{
	int		fd;
	int		pad;
	int		size;
	int		err;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU))
																		< 0)
	{
		err = errno;
		quit_failure(err, &game);
	}
	pad = (4 - ((game.real_screen.width * 3) % 4)) % 4;
	size = 54 + (3 * game.real_screen.width + pad) * game.real_screen.height;
	write_header(fd, size, game);
	write_content(fd, pad, game);
	if (close(fd) < 0)
	{
		err = errno;
		quit_failure(err, &game);
	}
	quit(&game);
}
