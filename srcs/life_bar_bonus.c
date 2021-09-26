/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:40:15 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:37:28 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	generate_heart(int n, t_game *game)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < game->config.heart_size)
	{
		j = 0;
		while (j < game->config.heart_size)
		{
			color = mlx_get_color_value(game->mlx_ptr,
					get_pixel_rgb_color(floor(i * game->config.hp_texture.height
					/ game->config.heart_size), floor(j
					* game->config.hp_texture.width
					/ game->config.heart_size), game->config.hp_texture));
			if (color != 0xFFFFFF)
				*((unsigned int*)(game->hud.data + game->hud.size_line
							* (game->config.y_life_bar + i) + 4
							* (game->config.x_life_bar + n
							* (game->config.heart_size + 5) + j))) = color;
			j++;
		}
		i++;
	}
}

static void	generate_dead_heart(int n, t_game *game)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < game->config.heart_size)
	{
		j = 0;
		while (j < game->config.heart_size)
		{
			color = mlx_get_color_value(game->mlx_ptr,
				get_pixel_rgb_color(floor(i * game->config.hpd_texture.height
				/ game->config.heart_size), floor(j
				* game->config.hpd_texture.width / game->config.heart_size),
				game->config.hpd_texture));
			if (color != 0xFFFFFF)
				*((unsigned int*)(game->hud.data + game->hud.size_line
								* (game->config.y_life_bar + i) + 4
								* (game->config.x_life_bar + n
								* (game->config.heart_size + 5) + j))) = color;
			j++;
		}
		i++;
	}
}

void		generate_life_bar(t_game *game)
{
	int		n;

	if (!game->bonus.hud
		|| game->config.resolution.width < game->config.min_resolution.width
		|| game->config.resolution.height < game->config.min_resolution.height)
		return ;
	n = 0;
	while (n < game->player.life)
	{
		generate_heart(n, game);
		n++;
	}
	while (n < LIFE)
	{
		generate_dead_heart(n, game);
		n++;
	}
	generate_reward_count(game);
}
