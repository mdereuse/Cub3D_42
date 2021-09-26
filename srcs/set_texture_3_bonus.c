/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:13:43 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:15:01 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_sp_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.config_check.sp_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.sp_texture),
																game, line)))
		return (ret_set_texture);
	game->config.config_check.sp_texture = true;
	game->clean_check.sp_texture = true;
	game->lvl.sp_texture = game->config.sp_texture;
	return (SUCCESS);
}

int		set_ex_sp_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_sp_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ex_sp_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_sp_texture = true;
	game->clean_check.ex_sp_texture = true;
	return (SUCCESS);
}

int		set_fl_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.fl_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.fl_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.fl_texture = true;
	game->clean_check.fl_texture = true;
	game->lvl.fl_texture = game->config.fl_texture;
	return (SUCCESS);
}

int		set_ex_fl_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_fl_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ex_fl_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_fl_texture = true;
	game->clean_check.ex_fl_texture = true;
	return (SUCCESS);
}

int		set_sky_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.sky_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.sky_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.sky_texture = true;
	game->clean_check.sky_texture = true;
	game->lvl.sky_texture = game->config.sky_texture;
	return (SUCCESS);
}
