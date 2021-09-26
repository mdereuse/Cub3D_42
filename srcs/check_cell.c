/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 07:03:57 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 19:16:02 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool			is_empty_space_corr(t_pos pos, double angle, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	correct_x_y(pos, angle, &x, &y);
	return (game->config.map[y][x] == ' ');
}

bool			is_empty_space(t_pos pos, t_game *game)
{
	t_cell	cell;

	if (out_map_pos(pos, game))
		return (false);
	cell = get_cell(pos);
	return (game->config.map[cell.y][cell.x] == ' ');
}

bool			is_wall_corr(t_pos pos, double angle, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	correct_x_y(pos, angle, &x, &y);
	return (game->config.map[y][x] == '1');
}

bool			is_sprite(t_pos pos, t_game *game)
{
	t_cell	cell;

	if (out_map_pos(pos, game))
		return (false);
	cell = get_cell(pos);
	return (game->config.map[cell.y][cell.x] == '2');
}

bool			is_sprite_corr(t_pos pos, double angle, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	correct_x_y(pos, angle, &x, &y);
	return (game->config.map[y][x] == '2');
}
