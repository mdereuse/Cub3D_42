/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:32:35 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:17:39 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	being_attacking(t_enemy *enemy, t_game *game)
{
	int		i;

	enemy->timer++;
	if (enemy->timer > game->config.attack_time)
	{
		enemy->timer = 0;
		enemy->state = BREATHING;
		damage(game);
		i = 0;
		while (i++ < 2)
			move_backward(game);
	}
}

void	being_breathing(t_enemy *enemy, t_game *game)
{
	enemy->timer++;
	if (enemy->timer > game->config.breathing_time)
	{
		enemy->timer = 0;
		enemy->state = WALKING;
	}
}

void	being_hurt(t_enemy *enemy, t_game *game)
{
	enemy->timer++;
	if (enemy->timer > game->config.hurt_time)
	{
		enemy->timer = 0;
		if (enemy->life > 0)
			enemy->state = BREATHING;
		else
			enemy->state = DYING;
	}
}

void	being_dying(t_enemy *enemy, t_game *game)
{
	enemy->timer++;
	if (enemy->timer > game->config.dying_time)
		enemy->state = DEAD;
}
