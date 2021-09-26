/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_const_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:45:06 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:23:31 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_time_speed_dist_const(t_game *game)
{
	game->config.waking_up_time = floor(15 * TIME_UNIT);
	game->config.surprised_time = floor(30 * TIME_UNIT);
	game->config.surprised_cling = floor(game->config.surprised_time / 3);
	game->config.walking_cling = floor(5 * TIME_UNIT);
	game->config.fst_attack_time = floor(3 * TIME_UNIT);
	game->config.attack_time = floor(7 * TIME_UNIT);
	game->config.breathing_time = floor(20 * TIME_UNIT);
	game->config.hurt_time = floor(20 * TIME_UNIT);
	game->config.hurt_cling = floor(game->config.hurt_time / 4);
	game->config.dying_time = floor(20 * TIME_UNIT);
	game->config.wp_anim_time = floor(2 * TIME_UNIT);
	game->config.glass_limit = floor(0.2 * BLOC_SIZE);
	game->config.view_distance = 18 * BLOC_SIZE;
	game->config.critical_distance = 8 * BLOC_SIZE;
	game->config.assault_distance = 1.3 * BLOC_SIZE;
	game->config.pick_distance = 1 * BLOC_SIZE;
	game->config.weapon_distance = 1 * BLOC_SIZE;
	game->config.crouch_height = floor(0.15 * BLOC_SIZE);
	game->config.player_speed = 0.1 * BLOC_SIZE;
	game->config.rotation_speed = 0.04;
	game->config.crouch_speed = floor(0.05 * BLOC_SIZE);
	game->config.jumping_u_speed = floor(0.05 * BLOC_SIZE);
	game->config.jumping_d_speed = floor(0.08 * BLOC_SIZE);
	game->config.look_speed = floor(0.1 * BLOC_SIZE);
	game->config.door_speed = floor(0.02 * BLOC_SIZE);
}

static void	set_animation_const(t_game *game)
{
	game->config.weapon_animation[0].time = 1;
	game->config.weapon_animation[0].picture = game->config.w1_texture;
	game->config.weapon_animation[1].time = 2;
	game->config.weapon_animation[1].picture = game->config.w2_texture;
	game->config.weapon_animation[2].time = 3;
	game->config.weapon_animation[2].picture = game->config.w3_texture;
	game->config.weapon_animation[3].time = 4;
	game->config.weapon_animation[3].picture = game->config.w4_texture;
	game->config.weapon_animation[4].time = 5;
	game->config.weapon_animation[4].picture = game->config.w5_texture;
	game->config.weapon_animation[5].time = 0;
}

static void	set_count_const(t_game *game)
{
	game->config.number[0].alpha = '0';
	game->config.number[0].image = game->config.nb0_texture;
	game->config.number[1].alpha = '1';
	game->config.number[1].image = game->config.nb1_texture;
	game->config.number[2].alpha = '2';
	game->config.number[2].image = game->config.nb2_texture;
	game->config.number[3].alpha = '3';
	game->config.number[3].image = game->config.nb3_texture;
	game->config.number[4].alpha = '4';
	game->config.number[4].image = game->config.nb4_texture;
	game->config.number[5].alpha = '5';
	game->config.number[5].image = game->config.nb5_texture;
	game->config.number[6].alpha = '6';
	game->config.number[6].image = game->config.nb6_texture;
	game->config.number[7].alpha = '7';
	game->config.number[7].image = game->config.nb7_texture;
	game->config.number[8].alpha = '8';
	game->config.number[8].image = game->config.nb8_texture;
	game->config.number[9].alpha = '9';
	game->config.number[9].image = game->config.nb9_texture;
}

static void	calculate_const(t_game *game)
{
	game->config.delta_rad = FOV / game->config.resolution.width;
	game->config.dist_screen = game->config.resolution.width
														/ (2 * tan(FOV / 2));
	game->config.thales_coeff = game->config.dist_screen * BLOC_SIZE;
	set_y_max(game);
	set_x_max(game);
	game->config.x_life_bar = floor(0.02 * game->config.resolution.width);
	game->config.y_life_bar = floor(0.04 * game->config.resolution.height);
	game->config.heart_size = floor((game->config.resolution.width / 3 - 45)
																		/ 10);
	game->config.x_rwd_icon = floor(0.02 * game->config.resolution.width);
	game->config.rwd_icon_size = floor(0.05 * game->config.resolution.width);
	game->config.y_rwd_icon = floor(game->config.resolution.height * 0.95)
												- game->config.rwd_icon_size;
	game->config.x_rwd_nmb = game->config.x_rwd_icon
												+ game->config.rwd_icon_size;
	game->config.y_rwd_nmb = game->config.y_rwd_icon;
	game->config.nmb_size = game->config.rwd_icon_size;
	game->config.message_width = floor(game->config.resolution.width / 2);
	game->config.message_height = floor(game->config.resolution.height / 3);
	game->config.x_message = floor((game->config.resolution.width
											- game->config.message_width) / 2);
	game->config.y_message = floor((game->config.resolution.height
											- game->config.message_height) / 2);
	game->config.hit_box = floor(game->config.resolution.width / 5);
}

void		set_const(t_game *game)
{
	set_time_speed_dist_const(game);
	set_animation_const(game);
	set_count_const(game);
	calculate_const(game);
	game->config.min_resolution.width = 200;
	game->config.min_resolution.height = floor(game->config.resolution.width
																		/ 4);
}
