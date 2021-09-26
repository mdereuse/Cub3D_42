/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_7_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:16:21 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:17:07 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_weapon2_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.w2_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.w2_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.w2_texture = true;
	game->clean_check.w2_texture = true;
	return (SUCCESS);
}

int		set_weapon3_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.w3_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.w3_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.w3_texture = true;
	game->clean_check.w3_texture = true;
	return (SUCCESS);
}

int		set_weapon4_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.w4_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.w4_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.w4_texture = true;
	game->clean_check.w4_texture = true;
	return (SUCCESS);
}

int		set_weapon5_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.w5_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.w5_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.w5_texture = true;
	game->clean_check.w5_texture = true;
	return (SUCCESS);
}

int		set_en_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.en_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.en_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.en_texture = true;
	game->clean_check.en_texture = true;
	return (SUCCESS);
}
