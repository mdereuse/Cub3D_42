/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:48:17 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 19:20:15 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

unsigned int	get_sky_pixel_color(int i, t_ray_cast ray_cast, t_game *game)
{
	t_image	texture;
	int		col;
	int		line;

	texture = game->lvl.sky_texture;
	col = floor(ray_cast.angle * texture.width / (2 * M_PI));
	line = floor((i + (game->config.resolution.height - game->player.eye))
							* texture.height / game->config.resolution.height);
	return (mlx_get_color_value(game->mlx_ptr,
									get_pixel_rgb_color(line, col, texture)));
}

unsigned int	get_door_pixel_color(t_wall_hit hit, int y, t_game *game)
{
	t_image		texture;
	double		x;
	t_cell		cell;
	double		open;

	if (hit.exit_lvl && game->lvl.finish)
		texture = game->config.exit_o_texture;
	else if (hit.exit_lvl)
		texture = game->config.exit_c_texture;
	else
		texture = game->config.door_texture;
	cell = get_cell(hit.pos);
	open = (100.0 - game->config.door_map[cell.y][cell.x]) / 100.0;
	if (hit.wall_type == NORTH || hit.wall_type == SOUTH)
		x = hit.pos.x - round_down_bs_mul(hit.pos.x) + (BLOC_SIZE * open);
	else
		x = hit.pos.y - round_down_bs_mul(hit.pos.y) + (BLOC_SIZE * open);
	return (mlx_get_color_value(game->mlx_ptr,
				get_pixel_rgb_color_shdw(get_opacity(hit.corr_dist, game),
				floor(((double)y / (double)hit.wall_size) * texture.height),
				floor((x / (double)BLOC_SIZE) * texture.width), texture)));
}

unsigned int	get_wall_pixel_color(t_wall_hit hit, int y, t_game *game)
{
	t_image		texture;
	double		x;
	int			line;
	int			col;

	if (hit.wall_type == NORTH)
		texture = game->lvl.so_texture;
	else if (hit.wall_type == SOUTH)
		texture = game->lvl.no_texture;
	else if (hit.wall_type == WEST)
		texture = game->lvl.ea_texture;
	else
		texture = game->lvl.we_texture;
	if (hit.wall_type == NORTH || hit.wall_type == SOUTH)
		x = hit.pos.x - round_down_bs_mul(hit.pos.x);
	else
		x = hit.pos.y - round_down_bs_mul(hit.pos.y);
	line = floor(((double)y / (double)hit.wall_size) * texture.height);
	col = floor((x / (double)BLOC_SIZE) * texture.width);
	return (mlx_get_color_value(game->mlx_ptr,
				get_pixel_rgb_color_shdw(get_opacity(hit.corr_dist, game), line,
				col, texture)));
}

unsigned int	get_floor_pixel_color(double dist, t_ray_cast ray_cast,
																t_game *game)
{
	double	delta_x;
	double	delta_y;
	int		col;
	int		line;

	delta_x = get_delta_x_floor(dist, ray_cast, game);
	delta_y = get_delta_y_floor(dist, ray_cast, game);
	col = floor(delta_x * game->config.fl_texture.width / BLOC_SIZE);
	line = floor(delta_y * game->config.fl_texture.height / BLOC_SIZE);
	return (mlx_get_color_value(game->mlx_ptr,
				get_pixel_rgb_color_shdw(get_opacity(dist, game), line, col,
				game->lvl.fl_texture)));
}

unsigned int	get_sprite_pixel_color(t_sp_hit hit, int y, t_game *game)
{
	int				line;
	int				col;

	col = floor(hit.col_coeff * hit.texture.width);
	if (col < 0 || col > hit.texture.width - 1)
		return (0);
	line = floor(((double)y / (double)hit.sp_size) * hit.texture.height);
	return (mlx_get_color_value(game->mlx_ptr,
				get_pixel_rgb_color_shdw(get_opacity(hit.center_dist, game),
				line, col, hit.texture)));
}
