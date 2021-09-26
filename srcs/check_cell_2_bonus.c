/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cell_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:25:42 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:14:07 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool			is_sprite(t_pos pos, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	x = floor(pos.x / BLOC_SIZE);
	y = floor(pos.y / BLOC_SIZE);
	return (game->config.map[y][x] == '2'
			|| (game->config.map[y][x] == '3' && game->bonus.bonus)
			|| (game->config.map[y][x] == '4' && game->bonus.trap)
			|| (game->config.map[y][x] == '5' && game->bonus.obstacle));
}

bool			is_sprite_corr(t_pos pos, double angle, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	correct_x_y(pos, angle, &x, &y);
	return (game->config.map[y][x] == '2'
			|| (game->config.map[y][x] == '3' && game->bonus.bonus)
			|| (game->config.map[y][x] == '4' && game->bonus.trap)
			|| (game->config.map[y][x] == '5' && game->bonus.obstacle));
}

bool			is_obstacle(t_pos pos, t_game *game)
{
	int		x;
	int		y;

	if (out_map_pos(pos, game))
		return (false);
	if (!game->bonus.obstacle)
		return (false);
	x = floor(pos.x / BLOC_SIZE);
	y = floor(pos.y / BLOC_SIZE);
	return (game->config.map[y][x] == '5');
}
