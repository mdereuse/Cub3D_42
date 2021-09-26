/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:14:37 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:15:41 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_ex_sky_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_sky_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture =
					set_texture(&(game->config.ex_sky_texture), game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_sky_texture = true;
	game->clean_check.ex_sky_texture = true;
	return (SUCCESS);
}

int		set_hp_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.hp_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.hp_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.hp_texture = true;
	game->clean_check.hp_texture = true;
	return (SUCCESS);
}

int		set_hpd_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.hpd_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.hpd_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.hpd_texture = true;
	game->clean_check.hpd_texture = true;
	return (SUCCESS);
}

int		set_go_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.go_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.go_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.go_texture = true;
	game->clean_check.go_texture = true;
	return (SUCCESS);
}

int		set_win_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.win_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.win_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.win_texture = true;
	game->clean_check.win_texture = true;
	return (SUCCESS);
}
