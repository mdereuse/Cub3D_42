/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 22:18:21 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:18:34 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

unsigned int	get_floor_color_shdw(double dist, t_game *game)
{
	double				opacity;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;

	opacity = get_opacity(dist, game);
	r = floor(game->config.floor_color.r * (1 - opacity));
	g = floor(game->config.floor_color.g * (1 - opacity));
	b = floor(game->config.floor_color.b * (1 - opacity));
	return (mlx_get_color_value(game->mlx_ptr, get_color_value(r, g, b)));
}
