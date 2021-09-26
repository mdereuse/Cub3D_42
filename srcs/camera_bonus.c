/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:23:46 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:13:27 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotation_left(t_game *game)
{
	double	orientation;

	orientation = game->player.orientation + game->config.rotation_speed;
	game->player.orientation = convert_angle(orientation);
}

void	rotation_right(t_game *game)
{
	double	orientation;

	orientation = game->player.orientation - game->config.rotation_speed;
	game->player.orientation = convert_angle(orientation);
}

void	look_down(t_game *game)
{
	double	new_eye;

	new_eye = game->player.eye - game->config.look_speed;
	game->player.eye = fmax(new_eye, 0);
}

void	look_up(t_game *game)
{
	double	new_eye;

	new_eye = game->player.eye + game->config.look_speed;
	game->player.eye = fmin(new_eye, game->config.resolution.height);
}
