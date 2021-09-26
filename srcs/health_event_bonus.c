/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_event_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:37:12 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:18:23 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	damage(t_game *game)
{
	if (game->player.life > 0)
		game->player.life--;
	if (game->player.life == 0)
		game->player.dead = true;
	generate_life_bar(game);
}

void	recup(t_game *game)
{
	if (game->player.life < LIFE)
		game->player.life++;
	generate_life_bar(game);
}

void	pick_item(t_game *game)
{
	t_cell		cell;

	if (!game->item_target.is_defined)
		return ;
	if (game->item_target.enemy)
	{
		game->rwd_count++;
		game->item_target.enemy->state = PICKED;
		generate_reward_count(game);
	}
	else
	{
		cell = get_cell(game->item_target.pos);
		if (game->config.map[cell.y][cell.x] == '5')
			return ;
		if (game->config.map[cell.y][cell.x] == '3' && game->bonus.bonus)
			recup(game);
		if (game->config.map[cell.y][cell.x] == '4' && game->bonus.trap)
			damage(game);
		game->config.map[cell.y][cell.x] = '0';
	}
}
