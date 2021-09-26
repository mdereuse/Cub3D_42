/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:31:27 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:41:29 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	black_screen(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->screen.height)
	{
		j = 0;
		while (j < game->screen.width)
		{
			*((unsigned int*)(game->screen.data + 4 * j
											+ game->screen.size_line * i)) = 0;
			j++;
		}
		i++;
	}
}

static int	generate_screen_default(t_game *game)
{
	int		ret;

	while (game->screen_generator.pix_col < game->config.resolution.width)
	{
		if (SUCCESS != (ret = cast_ray(game)))
			return (ret);
		game->screen_generator.pix_col++;
		game->screen_generator.angle =
									convert_angle(game->screen_generator.angle
									- game->config.delta_rad);
	}
	return (SUCCESS);
}

int			generate_screen(t_game *game)
{
	int		ret;

	game->screen_generator.pix_col = 0;
	game->screen_generator.angle = convert_angle(game->player.orientation
																	+ FOV / 2);
	ret = generate_screen_default(game);
	if (ERROR_BLACK == ret)
		black_screen(game);
	else if (SUCCESS != ret)
		return (ret);
	return (SUCCESS);
}
