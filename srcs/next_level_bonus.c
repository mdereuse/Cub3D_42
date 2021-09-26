/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:42:07 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:19:57 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	put_extra_set_textures(t_game *game)
{
	game->lvl.no_texture = game->config.ex_no_texture;
	game->lvl.so_texture = game->config.ex_so_texture;
	game->lvl.we_texture = game->config.ex_we_texture;
	game->lvl.ea_texture = game->config.ex_ea_texture;
	game->lvl.sp_texture = game->config.ex_sp_texture;
	game->lvl.bonus_texture = game->config.ex_bonus_texture;
	game->lvl.trap_texture = game->config.ex_trap_texture;
	game->lvl.obstacle_texture = game->config.ex_obstacle_texture;
	game->lvl.fl_texture = game->config.ex_fl_texture;
	game->lvl.sky_texture = game->config.ex_sky_texture;
}

static void	put_default_set_textures(t_game *game)
{
	game->lvl.no_texture = game->config.no_texture;
	game->lvl.so_texture = game->config.so_texture;
	game->lvl.we_texture = game->config.we_texture;
	game->lvl.ea_texture = game->config.ea_texture;
	game->lvl.sp_texture = game->config.sp_texture;
	game->lvl.bonus_texture = game->config.bonus_texture;
	game->lvl.trap_texture = game->config.trap_texture;
	game->lvl.obstacle_texture = game->config.obstacle_texture;
	game->lvl.fl_texture = game->config.fl_texture;
	game->lvl.sky_texture = game->config.sky_texture;
}

static void	change_textures(t_game *game)
{
	if (game->lvl.number % 2 && game->bonus.extra_textures)
		put_extra_set_textures(game);
	else
		put_default_set_textures(game);
}

void		next_lvl(t_game *game)
{
	int		count;

	game->param[DOOR].is_on = false;
	count = 0;
	while (game->config.maps[count])
		count++;
	if (game->lvl.number + 1 >= count)
	{
		game->victory = true;
		return ;
	}
	game->lvl.number++;
	game->config.map = game->config.maps[game->lvl.number];
	game->config.door_map = game->config.door_maps[game->lvl.number];
	game->config.timer_map = game->config.timer_maps[game->lvl.number];
	set_x_max(game);
	set_y_max(game);
	change_textures(game);
	set_player(game);
	if (SUCCESS != set_enemies(game))
		quit_failure(ERROR_MALLOC, game);
	generate_life_bar(game);
	game->lvl.finish = false;
}
