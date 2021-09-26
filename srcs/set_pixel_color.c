/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdereuse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:57:42 by mdereuse          #+#    #+#             */
/*   Updated: 2020/05/08 07:45:14 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_pixel_color(int line, int col, t_image texture,
																t_game *game)
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	int					rgb;

	b = *((unsigned char*)(texture.data + 4 * col + texture.size_line * line));
	g = *((unsigned char*)(texture.data + 4 * col + texture.size_line
																* line + 1));
	r = *((unsigned char*)(texture.data + 4 * col + texture.size_line
																* line + 2));
	rgb = get_color_value(r, g, b);
	return (mlx_get_color_value(game->mlx_ptr, rgb));
}

void			set_wall_pixel_color(char *data, t_wall_hit hit, int y,
																t_game *game)
{
	t_image		texture;
	double		x;
	int			line;
	int			col;

	if (hit.wall_type == NORTH)
		texture = game->config.so_texture;
	else if (hit.wall_type == SOUTH)
		texture = game->config.no_texture;
	else if (hit.wall_type == WEST)
		texture = game->config.ea_texture;
	else
		texture = game->config.we_texture;
	if (hit.wall_type == NORTH || hit.wall_type == SOUTH)
		x = hit.pos.x - round_down_bs_mul(hit.pos.x);
	else
		x = hit.pos.y - round_down_bs_mul(hit.pos.y);
	line = floor(((double)y / (double)hit.wall_size) * texture.height);
	col = floor((x / (double)BLOC_SIZE) * texture.width);
	*((unsigned int*)data) = get_pixel_color(line, col, texture, game);
}

void			set_sprite_pixel_color(char *data, t_sp_hit hit, int y,
																t_game *game)
{
	int				line;
	int				col;
	unsigned int	color;

	col = floor(hit.col_coeff * hit.texture.width);
	if (col < 0 || col > hit.texture.width - 1)
		return ;
	line = floor(((double)y / (double)hit.sp_size) * hit.texture.height);
	color = get_pixel_color(line, col, hit.texture, game);
	if (color != 0)
		*((unsigned int*)data) = color;
}
