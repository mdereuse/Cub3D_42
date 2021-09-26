/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:47:54 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:23:53 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		set_window(t_game *game)
{
	if (!(game->win_ptr = mlx_new_window(game->mlx_ptr,
									game->config.resolution.width,
									game->config.resolution.height, "Cub3D")))
		quit_failure(ERROR_MLX_NEW_WINDOW, game);
	game->clean_check.window = true;
}

void		set_game(t_game *game, char *file)
{
	if (!(game->mlx_ptr = mlx_init()))
		quit_failure(ERROR_MLX_INIT, game);
	game->clean_check.mlx_ptr = true;
	set_config(game, file);
	set_player(game);
	set_screen_image(game);
	set_hud_image(game);
	set_weapon_image(game);
	if (SUCCESS != set_enemies(game))
		quit_failure(ERROR_MALLOC, game);
}
