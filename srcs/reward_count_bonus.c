/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reward_count_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:43:32 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:38:20 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	generate_reward_count_number(t_image texture, int i, t_game *game)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < game->config.nmb_size)
	{
		x = 0;
		while (x < game->config.nmb_size)
		{
			color = mlx_get_color_value(game->mlx_ptr, get_pixel_rgb_color(
				floor(y * texture.height / game->config.nmb_size), floor(x
				* texture.width / game->config.nmb_size), texture));
			if (color != 0)
				*((unsigned int*)(game->hud.data + game->hud.size_line * (y
					+ game->config.y_rwd_nmb) + 4 * (x + game->config.x_rwd_nmb
					+ i * game->config.nmb_size))) = color;
			else
				*((unsigned char*)(game->hud.data + game->hud.size_line * (y
					+ game->config.y_rwd_nmb) + 4 * (x + game->config.x_rwd_nmb
					+ i * game->config.nmb_size) + 3)) = 255;
			x++;
		}
		y++;
	}
}

static void	generate_reward_count_numbers(t_game *game)
{
	char	*count;
	int		i;
	int		j;
	t_image	texture;
	int		n;

	count = ft_itoa(game->rwd_count);
	n = ft_strlen(count);
	if (n > 3)
		return ;
	i = 0;
	while (i < n)
	{
		j = 0;
		texture = game->config.number[j].image;
		while (j < 10)
		{
			if (count[i] == game->config.number[j].alpha)
				texture = game->config.number[j].image;
			j++;
		}
		generate_reward_count_number(texture, i, game);
		i++;
	}
	free(count);
}

static void	generate_reward_count_icon(t_game *game)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < game->config.rwd_icon_size)
	{
		j = 0;
		while (j < game->config.rwd_icon_size)
		{
			color = mlx_get_color_value(game->mlx_ptr,
					get_pixel_rgb_color(floor(i
						* game->config.rwd_icon_texture.height
						/ game->config.rwd_icon_size), floor(j
						* game->config.rwd_icon_texture.width
						/ game->config.rwd_icon_size),
						game->config.rwd_icon_texture));
			if (color != 0)
				*((unsigned int*)(game->hud.data + game->hud.size_line * (i
								+ game->config.y_rwd_icon) + 4 * (j
								+ game->config.x_rwd_icon))) = color;
			j++;
		}
		i++;
	}
}

void		generate_reward_count(t_game *game)
{
	if (game->config.resolution.width < game->config.min_resolution.width
		|| game->config.resolution.height < game->config.min_resolution.height)
		return ;
	generate_reward_count_icon(game);
	generate_reward_count_numbers(game);
}
