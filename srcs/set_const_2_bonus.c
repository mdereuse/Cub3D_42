/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_const_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:46:13 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:23:13 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		set_x_max(t_game *game)
{
	size_t	i;
	size_t	max_len;

	i = 0;
	max_len = 0;
	while (game->config.map[i])
	{
		if (ft_strlen(game->config.map[i]) > max_len)
			max_len = ft_strlen(game->config.map[i]);
		i++;
	}
	game->config.x_max = BLOC_SIZE * max_len;
	game->config.x_cell_max = (int)max_len;
}

void		set_y_max(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->config.map[i])
		i++;
	game->config.y_max = BLOC_SIZE * i;
	game->config.y_cell_max = (int)i;
}
