/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:13:10 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:14:04 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_ex_so_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_so_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ex_so_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_so_texture = true;
	game->clean_check.ex_so_texture = true;
	return (SUCCESS);
}

int		set_we_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.config_check.we_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.we_texture),
																game, line)))
		return (ret_set_texture);
	game->config.config_check.we_texture = true;
	game->clean_check.we_texture = true;
	game->lvl.we_texture = game->config.we_texture;
	return (SUCCESS);
}

int		set_ex_we_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_we_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ex_we_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_we_texture = true;
	game->clean_check.ex_we_texture = true;
	return (SUCCESS);
}

int		set_ea_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.config_check.ea_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ea_texture),
																game, line)))
		return (ret_set_texture);
	game->config.config_check.ea_texture = true;
	game->clean_check.ea_texture = true;
	game->lvl.ea_texture = game->config.ea_texture;
	return (SUCCESS);
}

int		set_ex_ea_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_ea_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ex_ea_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_ea_texture = true;
	game->clean_check.ex_ea_texture = true;
	return (SUCCESS);
}
