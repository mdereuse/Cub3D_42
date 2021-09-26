/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:27:31 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 19:14:19 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	clean_6(t_game *game)
{
	if (game->clean_check.map)
		clean_maps(game->config.maps);
	if (game->clean_check.door_map)
		clean_maps(game->config.door_maps);
	if (game->clean_check.timer_map)
		clean_maps(game->config.timer_maps);
	if (game->clean_check.window)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->clean_check.screen)
		mlx_destroy_image(game->mlx_ptr, game->screen.id);
	if (game->clean_check.real_screen)
		mlx_destroy_image(game->mlx_ptr, game->real_screen.id);
	if (game->clean_check.hud)
		mlx_destroy_image(game->mlx_ptr, game->hud.id);
	if (game->clean_check.weapon_screen)
		mlx_destroy_image(game->mlx_ptr, game->weapon_screen.id);
	if (game->clean_check.mlx_ptr)
		free(game->mlx_ptr);
	ft_lstclear(&(game->en_list), free);
}

void	clean(t_game *game)
{
	clean_1(game);
	clean_2(game);
	clean_3(game);
	clean_4(game);
	clean_5(game);
	clean_6(game);
}
