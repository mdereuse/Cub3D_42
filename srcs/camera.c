/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:21:25 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:28:08 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
