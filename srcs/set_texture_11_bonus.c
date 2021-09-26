/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_11_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:18:35 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:19:18 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		set_nb1_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb1_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb1_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb1_texture = true;
	game->clean_check.nb1_texture = true;
	return (SUCCESS);
}

int		set_nb2_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb2_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb2_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb2_texture = true;
	game->clean_check.nb2_texture = true;
	return (SUCCESS);
}

int		set_nb3_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb3_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb3_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb3_texture = true;
	game->clean_check.nb3_texture = true;
	return (SUCCESS);
}

int		set_nb4_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb4_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb4_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb4_texture = true;
	game->clean_check.nb4_texture = true;
	return (SUCCESS);
}

int		set_nb5_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.nb5_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.nb5_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.nb5_texture = true;
	game->clean_check.nb5_texture = true;
	return (SUCCESS);
}
