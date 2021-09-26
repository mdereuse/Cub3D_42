/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bonus_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:44:33 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:22:33 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_bonus_hud(t_game *game)
{
	game->bonus.hud = game->config.bonus_check.hp_texture
		&& game->config.bonus_check.hpd_texture
		&& game->config.bonus_check.go_texture
		&& game->config.bonus_check.rwd_icon_texture
		&& game->config.bonus_check.nb0_texture
		&& game->config.bonus_check.nb1_texture
		&& game->config.bonus_check.nb2_texture
		&& game->config.bonus_check.nb3_texture
		&& game->config.bonus_check.nb4_texture
		&& game->config.bonus_check.nb5_texture
		&& game->config.bonus_check.nb6_texture
		&& game->config.bonus_check.nb7_texture
		&& game->config.bonus_check.nb8_texture
		&& game->config.bonus_check.nb9_texture;
}

static void	set_bonus_weapon(t_game *game)
{
	game->bonus.weapon = game->config.bonus_check.w1_texture
		&& game->config.bonus_check.w2_texture
		&& game->config.bonus_check.w3_texture
		&& game->config.bonus_check.w4_texture
		&& game->config.bonus_check.w5_texture;
}

static void	set_bonus_enemy(t_game *game)
{
	game->bonus.enemy = game->config.bonus_check.en_texture
		&& game->config.bonus_check.ewu_texture
		&& game->config.bonus_check.es_texture
		&& game->config.bonus_check.ea1_texture
		&& game->config.bonus_check.ea2_texture
		&& game->config.bonus_check.eh1_texture
		&& game->config.bonus_check.eh2_texture
		&& game->config.bonus_check.ed_texture
		&& game->config.bonus_check.ewl_texture
		&& game->config.bonus_check.ewm_texture
		&& game->config.bonus_check.ewr_texture
		&& game->config.bonus_check.ewa_texture
		&& game->config.bonus_check.eb_texture
		&& game->config.bonus_check.rwd_texture;
}

static void	set_bonus_extra_textures(t_game *game)
{
	game->bonus.extra_textures = game->config.bonus_check.ex_no_texture
		&& game->config.bonus_check.ex_so_texture
		&& game->config.bonus_check.ex_we_texture
		&& game->config.bonus_check.ex_ea_texture
		&& game->config.bonus_check.ex_sp_texture
		&& game->config.bonus_check.ex_bonus_texture
		&& game->config.bonus_check.ex_trap_texture
		&& game->config.bonus_check.ex_obstacle_texture
		&& game->config.bonus_check.ex_fl_texture
		&& game->config.bonus_check.ex_sky_texture;
}

void		set_bonus(t_game *game)
{
	game->bonus.floor_texture = game->config.bonus_check.fl_texture;
	game->bonus.skybox = game->config.bonus_check.sky_texture;
	game->bonus.bonus = game->config.bonus_check.bonus_texture;
	game->bonus.trap = game->config.bonus_check.trap_texture;
	game->bonus.obstacle = game->config.bonus_check.obstacle_texture;
	game->bonus.door = (game->config.bonus_check.door_texture
						&& game->config.bonus_check.exit_o_texture
						&& game->config.bonus_check.exit_c_texture);
	game->bonus.win_screen = game->config.bonus_check.win_texture;
	set_bonus_hud(game);
	set_bonus_weapon(game);
	set_bonus_enemy(game);
	set_bonus_extra_textures(game);
}
