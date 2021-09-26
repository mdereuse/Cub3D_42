/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:27:13 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:16:31 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	clean_1(t_game *game)
{
	if (game->clean_check.no_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.no_texture.id);
	if (game->clean_check.so_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.so_texture.id);
	if (game->clean_check.we_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.we_texture.id);
	if (game->clean_check.ea_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ea_texture.id);
	if (game->clean_check.sp_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.sp_texture.id);
	if (game->clean_check.sky_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.sky_texture.id);
	if (game->clean_check.fl_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.fl_texture.id);
	if (game->clean_check.hp_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.hp_texture.id);
	if (game->clean_check.hpd_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.hpd_texture.id);
	if (game->clean_check.go_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.go_texture.id);
	if (game->clean_check.win_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.win_texture.id);
	if (game->clean_check.bonus_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.bonus_texture.id);
}

void	clean_2(t_game *game)
{
	if (game->clean_check.trap_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.trap_texture.id);
	if (game->clean_check.obstacle_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.obstacle_texture.id);
	if (game->clean_check.ex_no_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_no_texture.id);
	if (game->clean_check.ex_so_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_so_texture.id);
	if (game->clean_check.ex_we_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_we_texture.id);
	if (game->clean_check.ex_ea_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_ea_texture.id);
	if (game->clean_check.ex_sp_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_sp_texture.id);
	if (game->clean_check.ex_sky_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_sky_texture.id);
	if (game->clean_check.ex_fl_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_fl_texture.id);
	if (game->clean_check.ex_bonus_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_bonus_texture.id);
	if (game->clean_check.ex_trap_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_trap_texture.id);
	if (game->clean_check.ex_obstacle_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ex_obstacle_texture.id);
}

void	clean_3(t_game *game)
{
	if (game->clean_check.door_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.door_texture.id);
	if (game->clean_check.exit_o_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.exit_o_texture.id);
	if (game->clean_check.exit_c_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.exit_c_texture.id);
	if (game->clean_check.w1_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.w1_texture.id);
	if (game->clean_check.w2_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.w2_texture.id);
	if (game->clean_check.w3_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.w3_texture.id);
	if (game->clean_check.w4_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.w4_texture.id);
	if (game->clean_check.w5_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.w5_texture.id);
	if (game->clean_check.en_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.en_texture.id);
	if (game->clean_check.eh1_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.eh1_texture.id);
	if (game->clean_check.eh2_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.eh2_texture.id);
	if (game->clean_check.ed_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ed_texture.id);
}

void	clean_4(t_game *game)
{
	if (game->clean_check.es_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.es_texture.id);
	if (game->clean_check.ewu_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ewu_texture.id);
	if (game->clean_check.ea1_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ea1_texture.id);
	if (game->clean_check.ea2_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ea2_texture.id);
	if (game->clean_check.ewl_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ewl_texture.id);
	if (game->clean_check.ewr_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ewr_texture.id);
	if (game->clean_check.ewm_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ewm_texture.id);
	if (game->clean_check.eb_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.eb_texture.id);
	if (game->clean_check.ewa_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.ewa_texture.id);
	if (game->clean_check.rwd_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.rwd_texture.id);
	if (game->clean_check.rwd_icon_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.rwd_icon_texture.id);
	if (game->clean_check.nb0_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb0_texture.id);
}

void	clean_5(t_game *game)
{
	if (game->clean_check.nb1_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb1_texture.id);
	if (game->clean_check.nb2_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb2_texture.id);
	if (game->clean_check.nb3_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb3_texture.id);
	if (game->clean_check.nb4_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb4_texture.id);
	if (game->clean_check.nb5_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb5_texture.id);
	if (game->clean_check.nb6_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb6_texture.id);
	if (game->clean_check.nb7_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb7_texture.id);
	if (game->clean_check.nb8_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb8_texture.id);
	if (game->clean_check.nb9_texture)
		mlx_destroy_image(game->mlx_ptr, game->config.nb9_texture.id);
}
