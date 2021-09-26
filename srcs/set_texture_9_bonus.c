/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_9_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:17:29 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:18:20 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_ea2_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ea2_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ea2_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ea2_texture = true;
	game->clean_check.ea2_texture = true;
	return (SUCCESS);
}

int		set_ewl_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ewl_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ewl_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ewl_texture = true;
	game->clean_check.ewl_texture = true;
	return (SUCCESS);
}

int		set_ewr_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ewr_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ewr_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ewr_texture = true;
	game->clean_check.ewr_texture = true;
	return (SUCCESS);
}

int		set_ewm_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ewm_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ewm_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ewm_texture = true;
	game->clean_check.ewm_texture = true;
	return (SUCCESS);
}

int		set_ewu_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ewu_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ewu_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ewu_texture = true;
	game->clean_check.ewu_texture = true;
	return (SUCCESS);
}
