/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_around_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:40:35 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/08 07:41:18 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	look_current_cell(t_cell cell, char c, t_game *game)
{
	if (out_map_cell(cell, game))
		return (false);
	return (game->config.map[cell.y][cell.x] == c);
}

bool	look_up_cell(t_cell cell, char c, t_game *game)
{
	if (out_map_cell(cell, game))
		return (false);
	return (game->player.orientation > M_PI / 4
			&& game->player.orientation < 3 * M_PI / 4
			&& game->config.map[cell.y - 1][cell.x] == c);
}

bool	look_down_cell(t_cell cell, char c, t_game *game)
{
	if (out_map_cell(cell, game))
		return (false);
	return (game->player.orientation > 5 * M_PI / 4
			&& game->player.orientation < 7 * M_PI / 4
			&& game->config.map[cell.y + 1][cell.x] == c);
}

bool	look_left_cell(t_cell cell, char c, t_game *game)
{
	if (out_map_cell(cell, game))
		return (false);
	return (game->player.orientation > 3 * M_PI / 4
			&& game->player.orientation < 5 * M_PI / 4
			&& game->config.map[cell.y][cell.x - 1] == c);
}

bool	look_right_cell(t_cell cell, char c, t_game *game)
{
	if (out_map_cell(cell, game))
		return (false);
	return (((game->player.orientation > 7 * M_PI / 4
					&& game->player.orientation < 2 * M_PI)
				|| (game->player.orientation >= 0
					&& game->player.orientation < M_PI / 4))
			&& game->config.map[cell.y][cell.x + 1] == c);
}
