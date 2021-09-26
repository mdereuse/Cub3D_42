/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_texture_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:34:20 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:37:00 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_image		get_breathing_texture(t_enemy *enemy, t_game *game)
{
	(void)enemy;
	return (game->config.eb_texture);
}

t_image		get_hurt_texture(t_enemy *enemy, t_game *game)
{
	if (!((enemy->timer / game->config.hurt_cling) % 2))
		return (game->config.eh1_texture);
	else
		return (game->config.eh2_texture);
}

t_image		get_dying_texture(t_enemy *enemy, t_game *game)
{
	(void)enemy;
	return (game->config.ed_texture);
}

t_image		get_dead_texture(t_enemy *enemy, t_game *game)
{
	(void)enemy;
	return (game->config.rwd_texture);
}

t_image		get_picked_texture(t_enemy *enemy, t_game *game)
{
	(void)enemy;
	return (game->config.rwd_texture);
}
