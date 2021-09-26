/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:32:56 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:21:14 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "gl_enemy_behavior_bonus.h"

void	remove_if_enemy_dead(t_list **en_list)
{
	t_list	*current;
	t_list	*tmp;

	if (!en_list || !*en_list)
		return ;
	current = *en_list;
	while (current && current->next)
	{
		if (((t_enemy*)(current->next->content))->state == PICKED)
		{
			tmp = current->next;
			current->next = current->next->next;
			ft_lstdelone(tmp, free);
		}
		else
			current = current->next;
	}
	current = *en_list;
	if (((t_enemy*)(current->content))->state == PICKED)
	{
		*en_list = current->next;
		ft_lstdelone(current, free);
	}
}

void	actualize_enemies(t_game *game)
{
	t_list	*current;
	t_enemy	*enemy;
	int		i;

	current = game->en_list;
	while (current)
	{
		enemy = current->content;
		i = 0;
		while (g_behavior[i].fct)
		{
			if (g_behavior[i].state == enemy->state)
			{
				(*(g_behavior[i].fct))(enemy, game);
				break ;
			}
			i++;
		}
		current = current->next;
	}
}
