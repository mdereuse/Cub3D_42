/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_12_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:19:06 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:19:17 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_nb6_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb6_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb6_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb6_texture = true;
	game->clean_check.nb6_texture = true;
	return (SUCCESS);
}

int		set_nb7_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb7_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb7_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb7_texture = true;
	game->clean_check.nb7_texture = true;
	return (SUCCESS);
}

int		set_nb8_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb8_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb8_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb8_texture = true;
	game->clean_check.nb8_texture = true;
	return (SUCCESS);
}

int		set_nb9_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb9_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb9_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb9_texture = true;
	game->clean_check.nb9_texture = true;
	return (SUCCESS);
}
