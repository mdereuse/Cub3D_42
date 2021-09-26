/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_key_param.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:51:59 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:04:18 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_KEY_PARAM_H
# define GL_KEY_PARAM_H

# include "cub3d.h"

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
	{-1, -1}
};

#endif
