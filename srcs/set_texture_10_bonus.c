/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_10_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:18:07 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:18:52 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_eb_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.eb_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.eb_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.eb_texture = true;
	game->clean_check.eb_texture = true;
	return (SUCCESS);
}

int		set_ewa_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ewa_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ewa_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ewa_texture = true;
	game->clean_check.ewa_texture = true;
	return (SUCCESS);
}

int		set_rwd_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.rwd_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.rwd_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.rwd_texture = true;
	game->clean_check.rwd_texture = true;
	return (SUCCESS);
}

int		set_rwd_icon_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.rwd_icon_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture =
				set_texture(&(game->config.rwd_icon_texture), game, line)))
		return (ret_set_texture);
	game->config.bonus_check.rwd_icon_texture = true;
	game->clean_check.rwd_icon_texture = true;
	return (SUCCESS);
}

int		set_nb0_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb0_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb0_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb0_texture = true;
	game->clean_check.nb0_texture = true;
	return (SUCCESS);
}
