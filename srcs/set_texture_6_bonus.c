/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_6_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:15:53 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/08 07:39:06 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_ex_obstacle_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_obstacle_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture =
				set_texture(&(game->config.ex_obstacle_texture), game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_obstacle_texture = true;
	game->clean_check.ex_obstacle_texture = true;
	return (SUCCESS);
}

int		set_door_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.door_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.door_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.door_texture = true;
	game->clean_check.door_texture = true;
	return (SUCCESS);
}

int		set_exit_o_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.exit_o_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture =
					set_texture(&(game->config.exit_o_texture), game, line)))
		return (ret_set_texture);
	game->config.bonus_check.exit_o_texture = true;
	game->clean_check.exit_o_texture = true;
	return (SUCCESS);
}

int		set_exit_c_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.exit_c_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture =
					set_texture(&(game->config.exit_c_texture), game, line)))
		return (ret_set_texture);
	game->config.bonus_check.exit_c_texture = true;
	game->clean_check.exit_c_texture = true;
	return (SUCCESS);
}

int		set_weapon1_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.w1_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.w1_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.w1_texture = true;
	game->clean_check.w1_texture = true;
	return (SUCCESS);
}
