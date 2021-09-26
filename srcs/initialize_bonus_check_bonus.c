/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus_check_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:38:22 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:18:41 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	initialize_bonus_check_1(t_game *game)
{
	game->config.bonus_check.ex_no_texture = false;
	game->config.bonus_check.ex_so_texture = false;
	game->config.bonus_check.ex_we_texture = false;
	game->config.bonus_check.ex_ea_texture = false;
	game->config.bonus_check.ex_sp_texture = false;
	game->config.bonus_check.ex_fl_texture = false;
	game->config.bonus_check.ex_sky_texture = false;
	game->config.bonus_check.ex_bonus_texture = false;
	game->config.bonus_check.ex_trap_texture = false;
	game->config.bonus_check.ex_obstacle_texture = false;
	game->config.bonus_check.fl_texture = false;
	game->config.bonus_check.sky_texture = false;
	game->config.bonus_check.bonus_texture = false;
	game->config.bonus_check.trap_texture = false;
	game->config.bonus_check.obstacle_texture = false;
	game->config.bonus_check.hp_texture = false;
	game->config.bonus_check.hpd_texture = false;
	game->config.bonus_check.go_texture = false;
	game->config.bonus_check.win_texture = false;
	game->config.bonus_check.door_texture = false;
	game->config.bonus_check.exit_o_texture = false;
	game->config.bonus_check.exit_c_texture = false;
	game->config.bonus_check.w1_texture = false;
	game->config.bonus_check.w2_texture = false;
	game->config.bonus_check.w3_texture = false;
}

static void	initialize_bonus_check_2(t_game *game)
{
	game->config.bonus_check.w4_texture = false;
	game->config.bonus_check.w5_texture = false;
	game->config.bonus_check.en_texture = false;
	game->config.bonus_check.ewu_texture = false;
	game->config.bonus_check.es_texture = false;
	game->config.bonus_check.ea1_texture = false;
	game->config.bonus_check.ea2_texture = false;
	game->config.bonus_check.eh1_texture = false;
	game->config.bonus_check.eh2_texture = false;
	game->config.bonus_check.ed_texture = false;
	game->config.bonus_check.ewl_texture = false;
	game->config.bonus_check.ewr_texture = false;
	game->config.bonus_check.ewm_texture = false;
	game->config.bonus_check.ewa_texture = false;
	game->config.bonus_check.eb_texture = false;
	game->config.bonus_check.rwd_texture = false;
	game->config.bonus_check.rwd_icon_texture = false;
	game->config.bonus_check.nb0_texture = false;
	game->config.bonus_check.nb1_texture = false;
	game->config.bonus_check.nb2_texture = false;
	game->config.bonus_check.nb3_texture = false;
	game->config.bonus_check.nb4_texture = false;
	game->config.bonus_check.nb5_texture = false;
	game->config.bonus_check.nb6_texture = false;
	game->config.bonus_check.nb7_texture = false;
}

static void	initialize_bonus_check_3(t_game *game)
{
	game->config.bonus_check.nb8_texture = false;
	game->config.bonus_check.nb9_texture = false;
}

void		initialize_bonus_check(t_game *game)
{
	initialize_bonus_check_1(game);
	initialize_bonus_check_2(game);
	initialize_bonus_check_3(game);
}
