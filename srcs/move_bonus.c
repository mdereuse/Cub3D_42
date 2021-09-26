/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:41:46 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:19:49 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	move_collision(double angle, t_game *game)
{
	t_pos		test_pos;
	t_pos		new_pos;

	new_pos.x = game->player.pos.x;
	new_pos.y = game->player.pos.y;
	test_pos.x = game->player.pos.x + cos(angle) * game->config.player_speed;
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		test_pos.x -= game->config.glass_limit;
	else
		test_pos.x += game->config.glass_limit;
	test_pos.y = game->player.pos.y;
	if (is_new_pos_ok(test_pos, angle, game))
		new_pos.x = game->player.pos.x + cos(angle) * game->config.player_speed;
	test_pos.y = game->player.pos.y - sin(angle) * game->config.player_speed;
	if (angle > 0 && angle < M_PI)
		test_pos.y -= game->config.glass_limit;
	else
		test_pos.y += game->config.glass_limit;
	test_pos.x = game->player.pos.x;
	if (is_new_pos_ok(test_pos, angle, game))
		new_pos.y = game->player.pos.y - sin(angle) * game->config.player_speed;
	if (is_obstacle(new_pos, game))
		avoid_sprite(&new_pos, get_center_cell_pos(new_pos), angle, game);
	if (is_new_pos_ok(new_pos, angle, game))
		game->player.pos = new_pos;
}

void		move_forward(t_game *game)
{
	double		angle;

	angle = convert_angle(game->player.orientation);
	move_collision(angle, game);
}

void		move_backward(t_game *game)
{
	double		angle;

	angle = convert_angle(game->player.orientation + M_PI);
	move_collision(angle, game);
}

void		move_left(t_game *game)
{
	double		angle;

	angle = convert_angle(game->player.orientation + M_PI / 2);
	move_collision(angle, game);
}

void		move_right(t_game *game)
{
	double		angle;

	angle = convert_angle(game->player.orientation - M_PI / 2);
	move_collision(angle, game);
}
