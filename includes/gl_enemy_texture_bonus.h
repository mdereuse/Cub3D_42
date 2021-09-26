/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_enemy_texture_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:05:55 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:59:52 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_ENEMY_TEXTURE_BONUS_H
# define GL_ENEMY_TEXTURE_BONUS_H

# include "cub3d_bonus.h"

typedef t_image			(*t_fct_en_text)(t_enemy*, t_game*);

typedef struct			s_enemy_texture
{
	t_state				state;
	t_fct_en_text		fct;
}						t_enemy_texture;

const t_enemy_texture	g_enemy_texture[] =
{
	{WAITING, &get_waiting_texture},
	{WOKE_UP, &get_woke_up_texture},
	{SURPRISED, &get_surprised_texture},
	{WALKING, &get_walking_texture},
	{ATTACKING, &get_attacking_texture},
	{BREATHING, &get_breathing_texture},
	{HURT, &get_hurt_texture},
	{DYING, &get_dying_texture},
	{DEAD, &get_dead_texture},
	{PICKED, &get_picked_texture},
	{-1, NULL}
};

#endif
