/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crouch_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:30:47 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:16:57 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	crouch_down(t_game *game)
{
	game->player.posture = CROUCHING;
	game->player.head -= game->config.crouch_speed;
	if (game->player.head <= game->config.crouch_height)
	{
		game->player.head = game->config.crouch_height;
		game->param[CROUCH].is_on = false;
		game->player.posture = CROUCHED;
	}
}

static void	crouch_up(t_game *game)
{
	game->player.posture = STANDING_UP;
	game->player.head += game->config.crouch_speed;
	if (game->player.head >= BLOC_SIZE / 2)
	{
		game->player.head = BLOC_SIZE / 2;
		game->param[CROUCH].is_on = false;
		game->player.posture = STOOD_UP;
	}
}

void		crouch(t_game *game)
{
	if (game->player.posture == STOOD_UP
		|| game->player.posture == CROUCHING)
		crouch_down(game);
	else if (game->player.posture == CROUCHED
			|| game->player.posture == STANDING_UP)
		crouch_up(game);
	else
		game->param[CROUCH].is_on = false;
}
