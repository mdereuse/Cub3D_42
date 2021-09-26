/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cell_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:25:19 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:14:19 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool			is_exit_corr(t_pos pos, double angle, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	correct_x_y(pos, angle, &x, &y);
	return (game->config.map[y][x] == 'O' && game->bonus.door);
}

bool			is_door(t_pos pos, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	x = floor(pos.x / BLOC_SIZE);
	y = floor(pos.y / BLOC_SIZE);
	return ((game->config.map[y][x] == 'D' || game->config.map[y][x] == 'O')
			&& game->bonus.door);
}

bool			is_door_corr(t_pos pos, double angle, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	correct_x_y(pos, angle, &x, &y);
	return ((game->config.map[y][x] == 'D' || game->config.map[y][x] == 'O')
			&& game->bonus.door);
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

bool			is_wall_door_corr(t_pos pos, double angle, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	correct_x_y(pos, angle, &x, &y);
	return (is_wall_corr(pos, angle, game)
			|| (is_door_corr(pos, angle, game)
				&& game->config.door_map[y][x] != 0));
}
