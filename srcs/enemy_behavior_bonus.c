/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:32:18 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:18:32 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		being_waiting(t_enemy *enemy, t_game *game)
{
	if (get_dist(enemy->pos, game->player.pos) < game->config.critical_distance)
	{
		enemy->state = WOKE_UP;
		enemy->timer = 0;
	}
}

void		being_awake(t_enemy *enemy, t_game *game)
{
	enemy->timer++;
	if (enemy->timer > game->config.waking_up_time)
	{
		enemy->timer = 0;
		enemy->state = WALKING;
	}
}

void		walk(t_enemy *enemy, t_game *game)
{
	t_pos		new_pos;

	enemy->orientation = convert_angle(-atan2(enemy->pos.y
			- game->player.pos.y, enemy->pos.x - game->player.pos.x) + M_PI);
	new_pos.x = enemy->pos.x + cos(enemy->orientation) * 2;
	if (enemy->orientation > M_PI / 2 && enemy->orientation < 3 * M_PI / 2)
		new_pos.x -= 40;
	else
		new_pos.x += 40;
	new_pos.y = enemy->pos.y;
	if (!is_wall_door_corr(new_pos, enemy->orientation, game))
		enemy->pos.x = enemy->pos.x + cos(enemy->orientation) * 2;
	new_pos.y = enemy->pos.y - sin(enemy->orientation) * 2;
	if (enemy->orientation > 0 && enemy->orientation < M_PI)
		new_pos.y -= 40;
	else
		new_pos.y += 40;
	new_pos.x = enemy->pos.x;
	if (!is_wall_door_corr(new_pos, enemy->orientation, game))
		enemy->pos.y = enemy->pos.y - sin(enemy->orientation) * 2;
}

void		being_walking(t_enemy *enemy, t_game *game)
{
	double		dist;

	dist = get_dist(enemy->pos, game->player.pos);
	if (dist < game->config.critical_distance
		&& dist > game->config.assault_distance)
	{
		enemy->timer++;
		walk(enemy, game);
	}
	else
	{
		enemy->timer = 0;
		if (dist < game->config.critical_distance)
			enemy->state = ATTACKING;
		else
			enemy->state = SURPRISED;
	}
}

void		being_surprised(t_enemy *enemy, t_game *game)
{
	enemy->timer++;
	if (enemy->timer > game->config.surprised_time)
	{
		enemy->timer = 0;
		enemy->state = WAITING;
	}
}
