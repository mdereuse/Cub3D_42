/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:19:08 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:29:58 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_orientation(t_game *game, char c)
{
	double		orientation;

	orientation = 0;
	if (c == 'N')
		orientation = M_PI / 2;
	else if (c == 'W')
		orientation = M_PI;
	else if (c == 'S')
		orientation = 3 * M_PI / 2;
	game->player.orientation = orientation;
}

void		set_player(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->config.map[i])
	{
		j = 0;
		while (game->config.map[i][j])
		{
			if (is_in_set(game->config.map[i][j], "NSWE"))
			{
				game->player.pos.x = ((double)j + 0.5) * (double)BLOC_SIZE;
				game->player.pos.y = ((double)i + 0.5) * (double)BLOC_SIZE;
				set_orientation(game, game->config.map[i][j]);
				game->player.eye = game->config.resolution.height / 2;
				game->player.head = BLOC_SIZE / 2;
				return ;
			}
			j++;
		}
		i++;
	}
}
