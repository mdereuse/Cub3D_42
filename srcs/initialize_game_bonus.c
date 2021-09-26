/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:39:15 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:19:38 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	initialize_config_check(t_game *game)
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

void	initialize_params(t_game *game)
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
	game->param[LOOK_UP].fct = &look_up;
	game->param[LOOK_DOWN].fct = &look_down;
	game->param[CROUCH].fct = &crouch;
	game->param[JUMP].fct = &jump;
	game->param[EXIT].fct = &quit;
	game->param[DOOR].fct = &door_checking;
	game->param[WEAPON].fct = &activate_weapon;
	game->param[END].fct = NULL;
}

void	initialize_bonus(t_game *game)
{
	game->bonus.skybox = false;
	game->bonus.floor_texture = false;
	game->bonus.hud = false;
	game->bonus.bonus = false;
	game->bonus.trap = false;
	game->bonus.obstacle = false;
	game->bonus.door = false;
	game->bonus.weapon = false;
	game->bonus.enemy = false;
	game->bonus.extra_textures = false;
	game->bonus.win_screen = false;
}

void	initialize_game(t_game *game)
{
	game->mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	game->item_target.is_defined = false;
	game->en_list = NULL;
	game->victim = NULL;
	game->attack = false;
	game->weapon_timer = 0;
	game->rwd_count = 0;
	game->lvl.number = 0;
	game->lvl.finish = false;
	game->victory = false;
	initialize_clean_check(game);
	initialize_bonus_check(game);
	initialize_config_check(game);
	initialize_bonus(game);
	initialize_params(game);
}
