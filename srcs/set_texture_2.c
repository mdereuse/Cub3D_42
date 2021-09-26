/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:08:08 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:08:18 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (SUCCESS);
}

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
	return (SUCCESS);
}
