/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:39:45 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:20:07 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	jump_up(t_game *game)
{
	game->player.posture = JUMPING_UP;
	game->player.head += game->config.jumping_u_speed;
	if (game->player.head >= BLOC_SIZE)
	{
		game->player.head = BLOC_SIZE;
		game->player.posture = JUMPING_DOWN;
	}
}

static void	jump_down(t_game *game)
{
	game->player.head -= game->config.jumping_d_speed;
	if (game->player.head <= BLOC_SIZE / 2)
	{
		game->player.head = BLOC_SIZE / 2;
		game->param[JUMP].is_on = false;
		game->player.posture = STOOD_UP;
	}
}

void		jump(t_game *game)
{
	if (game->player.posture == STOOD_UP
		|| game->player.posture == JUMPING_UP)
		jump_up(game);
	else if (game->player.posture == JUMPING_DOWN)
		jump_down(game);
	else
		game->param[JUMP].is_on = false;
}
