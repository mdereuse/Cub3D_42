/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_5_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:15:20 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/08 07:40:50 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_bonus_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.bonus_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.bonus_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.bonus_texture = true;
	game->clean_check.bonus_texture = true;
	game->lvl.bonus_texture = game->config.bonus_texture;
	return (SUCCESS);
}

int		set_ex_bonus_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_bonus_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture =
				set_texture(&(game->config.ex_bonus_texture), game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_bonus_texture = true;
	game->clean_check.ex_bonus_texture = true;
	return (SUCCESS);
}

int		set_trap_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.trap_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.trap_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.trap_texture = true;
	game->clean_check.trap_texture = true;
	game->lvl.trap_texture = game->config.trap_texture;
	return (SUCCESS);
}

int		set_ex_trap_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_trap_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture =
				set_texture(&(game->config.ex_trap_texture), game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_trap_texture = true;
	game->clean_check.ex_trap_texture = true;
	return (SUCCESS);
}

int		set_obstacle_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.obstacle_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture =
					set_texture(&(game->config.obstacle_texture), game, line)))
		return (ret_set_texture);
	game->config.bonus_check.obstacle_texture = true;
	game->clean_check.obstacle_texture = true;
	game->lvl.obstacle_texture = game->config.obstacle_texture;
	return (SUCCESS);
}
