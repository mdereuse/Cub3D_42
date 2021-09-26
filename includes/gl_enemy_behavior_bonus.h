/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_enemy_behavior_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:04:51 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 18:27:29 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_ENEMY_BEHAVIOR_BONUS_H
# define GL_ENEMY_BEHAVIOR_BONUS_H

# include "cub3d_bonus.h"

typedef void		(*t_behavior_fct)(t_enemy*, t_game*);

typedef struct		s_behavior
{
	t_state			state;
	t_behavior_fct	fct;
}					t_behavior;

const t_behavior	g_behavior[] =
{
	{WAITING, &being_waiting},
	{WOKE_UP, &being_awake},
	{WALKING, &being_walking},
	{SURPRISED, &being_surprised},
	{ATTACKING, &being_attacking},
	{BREATHING, &being_breathing},
	{HURT, &being_hurt},
	{DYING, &being_dying},
	{-1, NULL}
};

#endif
