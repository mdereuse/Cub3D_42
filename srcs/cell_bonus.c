/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:24:22 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:13:37 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		correct_x_y(t_pos pos, double ray_angle, int *x, int *y)
{
	if (ray_angle >= M_PI / 2 && ray_angle < 3 * M_PI / 2)
		pos.x = ceil(pos.x - 1);
	if (ray_angle >= 0 && ray_angle < M_PI)
		pos.y = ceil(pos.y - 1);
	*x = floor(pos.x / BLOC_SIZE);
	*y = floor(pos.y / BLOC_SIZE);
}

t_cell		get_cell(t_pos pos)
{
	t_cell	cell;

	cell.x = floor(pos.x / BLOC_SIZE);
	cell.y = floor(pos.y / BLOC_SIZE);
	return (cell);
}

t_cell		get_cell_corr(t_pos pos, double angle)
{
	t_cell	cell;

	correct_x_y(pos, angle, &(cell.x), &(cell.y));
	return (cell);
}
