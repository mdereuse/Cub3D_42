/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_event_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:31:32 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/14 23:32:08 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int		find_door_cell(t_cell *cell, t_game *game)
{
	t_cell	p_cell;

	p_cell = get_cell(game->player.pos);
	if (look_current_cell(p_cell, 'D', game))
		*cell = p_cell;
	else if (look_up_cell(p_cell, 'D', game))
		*cell = get_up_cell(p_cell);
	else if (look_down_cell(p_cell, 'D', game))
		*cell = get_down_cell(p_cell);
	else if (look_left_cell(p_cell, 'D', game))
		*cell = get_left_cell(p_cell);
	else if (look_right_cell(p_cell, 'D', game))
		*cell = get_right_cell(p_cell);
	else
		return (-1);
	return (SUCCESS);
}

static int		find_exit_cell(t_cell *cell, t_game *game)
{
	t_cell	p_cell;

	p_cell = get_cell(game->player.pos);
	if (look_current_cell(p_cell, 'O', game))
		*cell = p_cell;
	else if (look_up_cell(p_cell, 'O', game))
		*cell = get_up_cell(p_cell);
	else if (look_down_cell(p_cell, 'O', game))
		*cell = get_down_cell(p_cell);
	else if (look_left_cell(p_cell, 'O', game))
		*cell = get_left_cell(p_cell);
	else if (look_right_cell(p_cell, 'O', game))
		*cell = get_right_cell(p_cell);
	else
		return (-1);
	return (SUCCESS);
}

void			activate_door(t_game *game)
{
	t_cell	cell;

	if (!game->bonus.door)
		return ;
	if (SUCCESS == find_exit_cell(&cell, game) && game->lvl.finish)
	{
		next_lvl(game);
		return ;
	}
	if (SUCCESS != find_door_cell(&cell, game)
		|| game->config.door_map[cell.y][cell.x] != 100)
		return ;
	game->param[DOOR].is_on = true;
	game->config.timer_map[cell.y][cell.x] = 100;
}
