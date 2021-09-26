/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:48:35 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:18:37 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		get_pixel_rgb_color(int line, int col, t_image texture)
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;

	b = *((unsigned char*)(texture.data + 4 * col + texture.size_line * line));
	g = *((unsigned char*)(texture.data + 4 * col + texture.size_line
																* line + 1));
	r = *((unsigned char*)(texture.data + 4 * col + texture.size_line
																* line + 2));
	return (get_color_value(r, g, b));
}

int		get_pixel_rgb_color_shdw(double opacity, int line, int col,
																t_image texture)
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;

	b = *((unsigned char*)(texture.data + 4 * col + texture.size_line * line));
	b = floor(b - b * opacity);
	g = *((unsigned char*)(texture.data + 4 * col + texture.size_line
																* line + 1));
	g = floor(g - g * opacity);
	r = *((unsigned char*)(texture.data + 4 * col + texture.size_line
																* line + 2));
	r = floor(r - r * opacity);
	return (get_color_value(r, g, b));
}

double	get_delta_x_floor(double dist, t_ray_cast ray_cast, t_game *game)
{
	double		x;
	double		delta_x;

	x = game->player.pos.x + cos(ray_cast.angle) * dist;
	delta_x = x - round_down_bs_mul(x);
	return (delta_x);
}

double	get_delta_y_floor(double dist, t_ray_cast ray_cast, t_game *game)
{
	double		y;
	double		delta_y;

	y = game->player.pos.y - sin(ray_cast.angle) * dist;
	delta_y = y - round_down_bs_mul(y);
	return (delta_y);
}

double	get_opacity(double dist, t_game *game)
{
	dist = fmin(dist, game->config.view_distance);
	return (dist / game->config.view_distance);
}
