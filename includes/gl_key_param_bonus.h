/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_key_param_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:07:26 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:35:39 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_KEY_PARAM_BONUS_H
# define GL_KEY_PARAM_BONUS_H

# include "cub3d_bonus.h"

typedef struct		s_key_param
{
	int				key_code;
	int				param_code;
}					t_key_param;

t_key_param const	g_key_press_param[] =
{
	{KEY_W, MOVE_FORWARD},
	{KEY_S, MOVE_BACKWARD},
	{KEY_A, MOVE_LEFT},
	{KEY_D, MOVE_RIGHT},
	{KEY_LEFT, ROT_LEFT},
	{KEY_RIGHT, ROT_RIGHT},
	{KEY_UP, LOOK_UP},
	{KEY_DOWN, LOOK_DOWN},
	{KEY_C, CROUCH},
	{KEY_SPACE, JUMP},
	{KEY_ESC, EXIT},
	{-1, -1}
};

t_key_param const	g_key_release_param[] =
{
	{KEY_W, MOVE_FORWARD},
	{KEY_S, MOVE_BACKWARD},
	{KEY_A, MOVE_LEFT},
	{KEY_D, MOVE_RIGHT},
	{KEY_LEFT, ROT_LEFT},
	{KEY_RIGHT, ROT_RIGHT},
	{KEY_UP, LOOK_UP},
	{KEY_DOWN, LOOK_DOWN},
	{-1, -1}
};

#endif
