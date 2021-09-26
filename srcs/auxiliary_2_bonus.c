/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:10:29 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:11:17 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		skip_spaces(char *line, size_t *index)
{
	while (line[*index] && line[*index] == ' ')
		(*index)++;
}

bool		skip_coma(char *line, size_t *index)
{
	skip_spaces(line, index);
	if (line[*index] && line[*index] == ',')
		(*index)++;
	else
		return (false);
	skip_spaces(line, index);
	return (true);
}

bool		out_map_pos(t_pos pos, t_game *game)
{
	return (pos.x <= 0
			|| pos.x >= game->config.x_max
			|| pos.y <= 0
			|| pos.y >= game->config.y_max);
}

bool		out_map_cell(t_cell cell, t_game *game)
{
	return (cell.x < 0
			|| cell.x > game->config.x_cell_max
			|| cell.y < 0
			|| cell.y > game->config.y_cell_max);
}
