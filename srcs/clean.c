/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:11:54 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 17:08:59 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean(t_game *game)
{
	if (game->clean_check.map)
		clean_map(game->config.map);
	if (game->clean_check.window)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->clean_check.screen)
		mlx_destroy_image(game->mlx_ptr, game->screen.id);
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
	if (game->clean_check.mlx_ptr)
		free(game->mlx_ptr);
}
