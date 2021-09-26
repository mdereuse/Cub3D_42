/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_event_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:31:53 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/14 23:45:59 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_closing(t_game *game)
{
	t_list		*current;
	t_enemy		*enemy;

	while (is_door(game->player.pos, game))
		move_backward(game);
	current = game->en_list;
	while (current)
	{
		enemy = current->content;
		while (is_door(enemy->pos, game))
			walk(enemy, game);
		current = current->next;
	}
}

static void	door_opening(int x, int y, t_game *game)
{
	game->config.door_map[y][x] -= game->config.door_speed;
	if (game->config.door_map[y][x] <= 0)
	{
		game->config.door_map[y][x] = 0;
		game->config.timer_map[y][x]--;
	}
}

static void	door_closing(int x, int y, t_game *game)
{
	check_closing(game);
	game->config.door_map[y][x] += game->config.door_speed;
	if (game->config.door_map[y][x] >= 100)
	{
		game->config.door_map[y][x] = 100;
		game->config.timer_map[y][x] = 0;
	}
}

static void	manage_door(int x, int y, t_game *game)
{
	if (game->config.timer_map[y][x] == 100)
		door_opening(x, y, game);
	else if (game->config.timer_map[y][x] < 100
			&& game->config.timer_map[y][x] > 50)
		game->config.timer_map[y][x]--;
	else if (game->config.timer_map[y][x] == 50)
		door_closing(x, y, game);
}

void		door_checking(t_game *game)
{
	size_t	i;
	size_t	j;
	int		count;

	count = 0;
	i = 0;
	while (game->config.map[i])
	{
		j = 0;
		while (game->config.map[i][j])
		{
			manage_door(j, i, game);
			if (game->config.timer_map[i][j] != 0)
				count++;
			j++;
		}
		i++;
	}
	if (!count)
		game->param[DOOR].is_on = false;
}
