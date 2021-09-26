/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_8_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:16:48 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:17:49 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_eh1_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.eh1_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.eh1_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.eh1_texture = true;
	game->clean_check.eh1_texture = true;
	return (SUCCESS);
}

int		set_eh2_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.eh2_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.eh2_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.eh2_texture = true;
	game->clean_check.eh2_texture = true;
	return (SUCCESS);
}

int		set_ed_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ed_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ed_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ed_texture = true;
	game->clean_check.ed_texture = true;
	return (SUCCESS);
}

int		set_es_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.es_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.es_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.es_texture = true;
	game->clean_check.es_texture = true;
	return (SUCCESS);
}

int		set_ea1_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ea1_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ea1_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ea1_texture = true;
	game->clean_check.ea1_texture = true;
	return (SUCCESS);
}
