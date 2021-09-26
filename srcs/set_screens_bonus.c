/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_screens_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:51:06 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/20 21:11:46 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		set_screen_image(t_game *game)
{
	if (!(game->screen.id = mlx_new_image(game->mlx_ptr,
									game->config.resolution.width,
									game->config.resolution.height)))
		quit_failure(ERROR_MLX_SCREEN, game);
	game->screen.width = game->config.resolution.width;
	game->screen.height = game->config.resolution.height;
	game->screen.data = mlx_get_data_addr(game->screen.id,
							&(game->screen.bpp), &(game->screen.size_line),
							&(game->screen.endian));
	game->clean_check.screen = true;
	if (!(game->real_screen.id = mlx_new_image(game->mlx_ptr,
									game->config.resolution.width,
									game->config.resolution.height)))
		quit_failure(ERROR_MLX_SCREEN, game);
	game->real_screen.width = game->config.resolution.width;
	game->real_screen.height = game->config.resolution.height;
	game->real_screen.data = mlx_get_data_addr(game->real_screen.id,
							&(game->real_screen.bpp),
							&(game->real_screen.size_line),
							&(game->real_screen.endian));
	game->clean_check.real_screen = true;
}

void		set_hud_image(t_game *game)
{
	if (!(game->hud.id = mlx_new_image(game->mlx_ptr,
									game->config.resolution.width,
									game->config.resolution.height)))
		quit_failure(ERROR_MLX_SCREEN, game);
	game->hud.width = game->config.resolution.width;
	game->hud.height = game->config.resolution.height;
	game->hud.data = mlx_get_data_addr(game->hud.id,
							&(game->hud.bpp), &(game->hud.size_line),
							&(game->hud.endian));
	game->clean_check.hud = true;
	clean_screen(game->hud);
	generate_hud(game);
}

void		set_weapon_image(t_game *game)
{
	if (!(game->weapon_screen.id = mlx_new_image(game->mlx_ptr,
				game->config.resolution.width, game->config.resolution.height)))
		quit_failure(ERROR_MLX_SCREEN, game);
	game->weapon_screen.width = game->config.resolution.width;
	game->weapon_screen.height = game->config.resolution.height;
	game->weapon_screen.data = mlx_get_data_addr(game->weapon_screen.id,
				&(game->weapon_screen.bpp), &(game->weapon_screen.size_line),
				&(game->weapon_screen.endian));
	game->clean_check.weapon_screen = true;
	clean_screen(game->weapon_screen);
	game->config.size_weapon = fmin(floor(game->config.resolution.width / 1.3),
												game->config.resolution.height);
	game->config.x_weapon = floor((game->config.resolution.width
											- game->config.size_weapon) / 2);
	game->config.y_weapon = floor(game->config.resolution.height
												- game->config.size_weapon);
}
