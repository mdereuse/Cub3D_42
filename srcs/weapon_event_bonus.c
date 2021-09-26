/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_event_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:53:11 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:27:08 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	assault(t_game *game)
{
	if (!game->attack || game->victim->state == HURT || game->victim->life <= 0)
		return ;
	game->victim->life -= DAMAGE;
	game->victim->state = HURT;
	game->victim->timer = 0;
}

void		activate_weapon(t_game *game)
{
	t_image		texture;
	int			i;

	texture = game->config.w1_texture;
	i = 0;
	while (game->config.weapon_animation[i].time)
	{
		if (game->weapon_timer < game->config.weapon_animation[i].time
													* game->config.wp_anim_time)
		{
			texture = game->config.weapon_animation[i].picture;
			break ;
		}
		i++;
	}
	if (game->weapon_timer == game->config.wp_anim_time * 4)
		assault(game);
	game->weapon_timer++;
	if (game->weapon_timer == game->config.wp_anim_time * 6)
	{
		clean_screen(game->weapon_screen);
		game->param[WEAPON].is_on = false;
	}
	else
		generate_weapon(texture, game);
}

void		try_activate_weapon(t_game *game)
{
	if (!game->bonus.weapon || game->param[WEAPON].is_on)
		return ;
	game->param[WEAPON].is_on = true;
	game->weapon_timer = 0;
}
