/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:10:57 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:12:20 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_pos		get_center_cell_corr(t_pos hit_pos, double angle)
{
	int		x;
	int		y;
	t_pos	center_pos;

	correct_x_y(hit_pos, angle, &x, &y);
	center_pos.x = BLOC_SIZE * (x + 0.5);
	center_pos.y = BLOC_SIZE * (y + 0.5);
	return (center_pos);
}

t_pos		get_center_cell_pos(t_pos pos)
{
	t_cell	cell;
	t_pos	center_pos;

	cell = get_cell(pos);
	center_pos.x = BLOC_SIZE * (cell.x + 0.5);
	center_pos.y = BLOC_SIZE * (cell.y + 0.5);
	return (center_pos);
}

double		get_alpha_angle(t_pos center_pos, t_player player)
{
	return (convert_angle(-atan2(center_pos.y - player.pos.y,
										center_pos.x - player.pos.x)));
}

double		get_beta_angle(t_pos center_pos, double angle, t_player player)
{
	return (convert_angle(get_alpha_angle(center_pos, player) - angle));
}

char		**add_new_line_to_map(char *new_line, char **old_map)
{
	char		**new_map;
	size_t		i;

	i = 0;
	while (old_map[i])
		i++;
	if (!(new_map = (char**)malloc(sizeof(*new_map) * (i + 2))))
		return (NULL);
	i = 0;
	while (old_map[i])
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[i++] = new_line;
	new_map[i] = NULL;
	return (new_map);
}
