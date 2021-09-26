/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_screens_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:14:09 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 19:41:15 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	is_transparent(char *pixel)
{
	unsigned char	a;

	a = *((unsigned char*)(pixel + 3));
	return (a == 255);
}

static bool	is_hud_transparent(int i, int j, t_game *game)
{
	return (is_transparent(game->hud.data + 4 * j + game->hud.size_line * i));
}

static bool	is_weapon_transparent(int i, int j, t_game *game)
{
	return (is_transparent(game->weapon_screen.data + 4 * j
				+ game->weapon_screen.size_line * i));
}

static void	fill_real_screen(int i, int j, t_game *game)
{
	if (!is_hud_transparent(i, j, game))
		*((unsigned int*)(game->real_screen.data + 4 * j
					+ game->real_screen.size_line * i)) =
			*((unsigned int*)(game->hud.data + 4 * j
						+ game->hud.size_line * i));
	else if (!is_weapon_transparent(i, j, game))
		*((unsigned int*)(game->real_screen.data + 4 * j
					+ game->real_screen.size_line * i)) =
			*((unsigned int*)(game->weapon_screen.data + 4 * j
						+ game->weapon_screen.size_line * i));
	else
		*((unsigned int*)(game->real_screen.data + 4 * j
					+ game->real_screen.size_line * i)) =
			*((unsigned int*)(game->screen.data + 4 * j
						+ game->screen.size_line * i));
}

void		push_screen_and_shadow(t_game *game)
{
	int				i;
	int				j;

	i = 0;
	while (i < game->config.resolution.height)
	{
		j = 0;
		while (j < game->config.resolution.width)
		{
			fill_real_screen(i, j, game);
			j++;
		}
		i++;
	}
}
