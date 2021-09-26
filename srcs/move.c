/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:32:25 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:36:28 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move(double angle, t_game *game)
{
	t_pos		new_pos;

	new_pos.x = game->player.pos.x + cos(angle) * game->config.player_speed;
	new_pos.y = game->player.pos.y - sin(angle) * game->config.player_speed;
	if (new_pos.x > 0
			&& new_pos.x < game->config.x_max
			&& new_pos.y > 0
			&& new_pos.y < game->config.y_max)
		game->player.pos = new_pos;
}

void		move_forward(t_game *game)
{
	double		angle;

	angle = convert_angle(game->player.orientation);
	move(angle, game);
}

void		move_backward(t_game *game)
{
	double		angle;

	angle = convert_angle(game->player.orientation + M_PI);
	move(angle, game);
}

void		move_left(t_game *game)
{
	double		angle;

	angle = convert_angle(game->player.orientation + M_PI / 2);
	move(angle, game);
}

void		move_right(t_game *game)
{
	double		angle;

	angle = convert_angle(game->player.orientation - M_PI / 2);
	move(angle, game);
}
