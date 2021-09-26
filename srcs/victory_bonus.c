/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:38:08 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 18:56:58 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	generate_victory_screen(t_game *game)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < game->config.message_height)
	{
		j = 0;
		while (j < game->config.message_width)
		{
			color = mlx_get_color_value(game->mlx_ptr,
				get_pixel_rgb_color(floor(i * game->config.win_texture.height
				/ game->config.message_height), floor(j
				* game->config.win_texture.width
				/ game->config.message_width), game->config.win_texture));
			*((unsigned int*)(game->screen.data + (i + game->config.y_message)
					* game->screen.size_line + (j + game->config.x_message)
					* 4)) = color;
			j++;
		}
		i++;
	}
}

void	generate_victory_screen_default(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->screen.height)
	{
		j = 0;
		while (j < game->screen.width)
		{
			*((unsigned int*)(game->screen.data + i
								* game->screen.size_line + j * 4)) = 0;
			j++;
		}
		i++;
	}
}

int		victory(t_game *game)
{
	generate_victory_screen_default(game);
	if (game->config.resolution.width >= game->config.min_resolution.width
		&& game->config.resolution.height >= game->config.min_resolution.height)
		generate_victory_screen(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->screen.id,
																		0, 0);
	return (0);
}
