/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:33:57 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:36:41 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_image		get_waiting_texture(t_enemy *enemy, t_game *game)
{
	(void)enemy;
	return (game->config.ewa_texture);
}

t_image		get_woke_up_texture(t_enemy *enemy, t_game *game)
{
	(void)enemy;
	return (game->config.ewu_texture);
}

t_image		get_surprised_texture(t_enemy *enemy, t_game *game)
{
	if ((enemy->timer / game->config.surprised_cling) % 2)
		return (game->config.es_texture);
	else
		return (game->config.en_texture);
}

t_image		get_walking_texture(t_enemy *enemy, t_game *game)
{
	if (((enemy->timer / game->config.walking_cling) % 3) == 0)
		return (game->config.ewl_texture);
	if (((enemy->timer / game->config.walking_cling) % 3) == 1)
		return (game->config.ewm_texture);
	else
		return (game->config.ewr_texture);
}

t_image		get_attacking_texture(t_enemy *enemy, t_game *game)
{
	if (enemy->timer < game->config.fst_attack_time)
		return (game->config.ea1_texture);
	else
		return (game->config.ea2_texture);
}
