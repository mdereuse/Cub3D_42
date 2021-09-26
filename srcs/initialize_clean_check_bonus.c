/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_clean_check_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:38:50 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 19:13:37 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	initialize_clean_check_1(t_game *game)
{
	game->clean_check.no_texture = false;
	game->clean_check.so_texture = false;
	game->clean_check.we_texture = false;
	game->clean_check.ea_texture = false;
	game->clean_check.sp_texture = false;
	game->clean_check.fl_texture = false;
	game->clean_check.sky_texture = false;
	game->clean_check.bonus_texture = false;
	game->clean_check.trap_texture = false;
	game->clean_check.obstacle_texture = false;
	game->clean_check.ex_no_texture = false;
	game->clean_check.ex_so_texture = false;
	game->clean_check.ex_we_texture = false;
	game->clean_check.ex_ea_texture = false;
	game->clean_check.ex_sp_texture = false;
	game->clean_check.ex_fl_texture = false;
	game->clean_check.ex_sky_texture = false;
	game->clean_check.ex_bonus_texture = false;
	game->clean_check.ex_trap_texture = false;
	game->clean_check.ex_obstacle_texture = false;
	game->clean_check.hp_texture = false;
	game->clean_check.hpd_texture = false;
	game->clean_check.go_texture = false;
	game->clean_check.win_texture = false;
	game->clean_check.door_texture = false;
}

static void	initialize_clean_check_2(t_game *game)
{
	game->clean_check.exit_o_texture = false;
	game->clean_check.exit_c_texture = false;
	game->clean_check.w1_texture = false;
	game->clean_check.w2_texture = false;
	game->clean_check.w3_texture = false;
	game->clean_check.w4_texture = false;
	game->clean_check.w5_texture = false;
	game->clean_check.en_texture = false;
	game->clean_check.ewu_texture = false;
	game->clean_check.es_texture = false;
	game->clean_check.ea1_texture = false;
	game->clean_check.ea2_texture = false;
	game->clean_check.eh1_texture = false;
	game->clean_check.eh2_texture = false;
	game->clean_check.ed_texture = false;
	game->clean_check.ewl_texture = false;
	game->clean_check.ewr_texture = false;
	game->clean_check.ewm_texture = false;
	game->clean_check.ewa_texture = false;
	game->clean_check.eb_texture = false;
	game->clean_check.rwd_texture = false;
	game->clean_check.rwd_icon_texture = false;
	game->clean_check.nb0_texture = false;
	game->clean_check.nb1_texture = false;
	game->clean_check.nb2_texture = false;
}

static void	initialize_clean_check_3(t_game *game)
{
	game->clean_check.nb3_texture = false;
	game->clean_check.nb4_texture = false;
	game->clean_check.nb5_texture = false;
	game->clean_check.nb6_texture = false;
	game->clean_check.nb7_texture = false;
	game->clean_check.nb8_texture = false;
	game->clean_check.nb9_texture = false;
	game->clean_check.map = false;
	game->clean_check.door_map = false;
	game->clean_check.timer_map = false;
	game->clean_check.window = false;
	game->clean_check.screen = false;
	game->clean_check.real_screen = false;
	game->clean_check.hud = false;
	game->clean_check.weapon_screen = false;
	game->clean_check.mlx_ptr = false;
}

void		initialize_clean_check(t_game *game)
{
	initialize_clean_check_1(game);
	initialize_clean_check_2(game);
	initialize_clean_check_3(game);
}
