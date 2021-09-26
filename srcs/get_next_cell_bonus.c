/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cell_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:36:30 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:18:17 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_cell	get_up_cell(t_cell cell)
{
	t_cell	new_cell;

	new_cell.x = cell.x;
	new_cell.y = cell.y - 1;
	return (new_cell);
}

t_cell	get_down_cell(t_cell cell)
{
	t_cell	new_cell;

	new_cell.x = cell.x;
	new_cell.y = cell.y + 1;
	return (new_cell);
}

t_cell	get_left_cell(t_cell cell)
{
	t_cell	new_cell;

	new_cell.x = cell.x - 1;
	new_cell.y = cell.y;
	return (new_cell);
}

t_cell	get_right_cell(t_cell cell)
{
	t_cell	new_cell;

	new_cell.x = cell.x + 1;
	new_cell.y = cell.y;
	return (new_cell);
}
