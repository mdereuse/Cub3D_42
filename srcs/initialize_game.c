/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:44:55 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:59:57 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_config_check(t_game *game)
{
	game->config.config_check.resolution = false;
	game->config.config_check.no_texture = false;
	game->config.config_check.so_texture = false;
	game->config.config_check.we_texture = false;
	game->config.config_check.ea_texture = false;
	game->config.config_check.sp_texture = false;
	game->config.config_check.floor_color = false;
	game->config.config_check.ceiling_color = false;
}

static void	initialize_params(t_game *game)
{
	int		i;

	i = 0;
	while (i < END + 1)
		game->param[i++].is_on = false;
	game->param[MOVE_FORWARD].fct = &move_forward;
	game->param[MOVE_BACKWARD].fct = &move_backward;
	game->param[MOVE_LEFT].fct = &move_left;
	game->param[MOVE_RIGHT].fct = &move_right;
	game->param[ROT_LEFT].fct = &rotation_left;
	game->param[ROT_RIGHT].fct = &rotation_right;
	game->param[EXIT].fct = &quit;
	game->param[END].fct = NULL;
}

static void	initialize_clean_check(t_game *game)
{
	game->clean_check.no_texture = false;
	game->clean_check.so_texture = false;
	game->clean_check.we_texture = false;
	game->clean_check.ea_texture = false;
	game->clean_check.sp_texture = false;
	game->clean_check.map = false;
	game->clean_check.window = false;
	game->clean_check.screen = false;
	game->clean_check.mlx_ptr = false;
}

void		initialize_game(t_game *game)
{
	initialize_clean_check(game);
	initialize_config_check(game);
	initialize_params(game);
}
