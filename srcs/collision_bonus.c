/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:30:10 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:16:48 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	check_dist_enemies(t_pos pos, t_game *game)
{
	t_list	*current;
	t_enemy	*enemy;

	if (!game->en_list)
		return (true);
	current = game->en_list;
	while (current)
	{
		enemy = current->content;
		if (get_dist(pos, enemy->pos) < 30)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	is_new_pos_ok(t_pos pos, double angle, t_game *game)
{
	return (!is_wall_door_corr(pos, angle, game)
			&& check_dist_enemies(pos, game));
}

void	avoid_sprite(t_pos *pos, t_pos sp_pos, double angle, t_game *game)
{
	double		dist;
	double		alpha_angle;
	double		gamma_angle;
	double		speed;
	double		new_angle;

	if (get_dist(sp_pos, *pos) > 30)
		return ;
	dist = get_dist(game->player.pos, *pos);
	alpha_angle = convert_angle(-atan2(sp_pos.y - game->player.pos.y,
							sp_pos.x - game->player.pos.x));
	gamma_angle = convert_angle(alpha_angle - angle);
	speed = fabs(sin(gamma_angle) * dist);
	if (sin(gamma_angle) < 0)
		new_angle = convert_angle(alpha_angle + M_PI / 2);
	else
		new_angle = convert_angle(alpha_angle - M_PI / 2);
	pos->x = game->player.pos.x + cos(new_angle) * speed;
	pos->y = game->player.pos.y - sin(new_angle) * speed;
}
