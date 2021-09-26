/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_screens_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:53:29 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 19:36:24 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static unsigned int	get_weapon_pixel_color(int i, int j, t_image texture,
																t_game *game)
{
	return (mlx_get_color_value(game->mlx_ptr, get_pixel_rgb_color(floor(i
					* texture.height / game->config.size_weapon),
					floor(j * texture.width / game->config.size_weapon),
					texture)));
}

void				generate_weapon(t_image texture, t_game *game)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < game->config.size_weapon)
	{
		j = 0;
		while (j < game->config.size_weapon)
		{
			color = get_weapon_pixel_color(i, j, texture, game);
			if (color != 0)
				*((unsigned int*)(game->weapon_screen.data
					+ game->weapon_screen.size_line * (i
					+ game->config.y_weapon) + 4 * (j
					+ game->config.x_weapon))) = color;
			else
				*((unsigned char*)(game->weapon_screen.data
					+ game->weapon_screen.size_line * (i
					+ game->config.y_weapon) + 4 * (j + game->config.x_weapon)
					+ 3)) = 255;
			j++;
		}
		i++;
	}
}

void				generate_hud(t_game *game)
{
	if (!game->bonus.hud)
		return ;
	generate_life_bar(game);
	generate_reward_count(game);
}
