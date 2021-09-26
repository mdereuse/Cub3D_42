/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_and_kick_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:42:49 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/08 07:07:06 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void			get_closest_sprite(t_list *sp_list, t_game *game)
{
	int			lst_size;
	t_sp_hit	hit;
	t_list		*current;

	lst_size = ft_lstsize(sp_list);
	while ((current = ft_lstat(sp_list, lst_size - 1)))
	{
		hit = *((t_sp_hit*)current->content);
		if (hit.dist > game->config.pick_distance)
			return ;
		if (!hit.enemy || hit.enemy->state == DEAD)
		{
			if (!game->item_option.is_defined)
			{
				game->item_option.is_defined = true;
				game->item_option.sp_hit = hit;
			}
			else if (hit.dist < game->item_option.sp_hit.dist)
				game->item_option.sp_hit = hit;
			return ;
		}
		lst_size--;
	}
}

void			get_closest_enemy(t_list *sp_list, t_game *game)
{
	int			lst_size;
	t_sp_hit	hit;
	t_list		*current;

	lst_size = ft_lstsize(sp_list);
	while ((current = ft_lstat(sp_list, lst_size - 1)))
	{
		hit = *((t_sp_hit*)current->content);
		if (hit.dist > game->config.weapon_distance)
			break ;
		if (hit.enemy && abs(game->config.resolution.width / 2 - hit.center_x)
				< game->config.hit_box)
		{
			game->attack = true;
			game->victim = hit.enemy;
			return ;
		}
		lst_size--;
	}
	game->attack = false;
}

void			pick_and_kick(t_list *sp_list, t_engine *engine)
{
	pthread_mutex_lock(&(engine->game->mutex));
	get_closest_sprite(sp_list, engine->game);
	if (engine->pix_col == (int)(floor(engine->game->config.resolution.width
																		/ 2)))
		get_closest_enemy(sp_list, engine->game);
	pthread_mutex_unlock(&(engine->game->mutex));
}

void			define_item_to_pick(t_game *game)
{
	if (game->item_option.is_defined)
	{
		game->item_target.is_defined = true;
		game->item_target.enemy = game->item_option.sp_hit.enemy;
		game->item_target.pos = game->item_option.sp_hit.center_pos;
	}
	else
		game->item_target.is_defined = false;
}
