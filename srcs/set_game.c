/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:42:42 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:31:01 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
}
