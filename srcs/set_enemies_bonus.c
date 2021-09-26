/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemies_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:47:36 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/14 23:46:23 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_enemy	*create_new_enemy(int x, int y)
{
	t_enemy	*new_enemy;

	if (!(new_enemy = (t_enemy*)malloc(sizeof(*new_enemy))))
		return (NULL);
	new_enemy->pos.x = BLOC_SIZE * (x + 0.5);
	new_enemy->pos.y = BLOC_SIZE * (y + 0.5);
	new_enemy->orientation = 3 * M_PI / 2;
	new_enemy->life = LIFE;
	new_enemy->state = WAITING;
	return (new_enemy);
}

static int		add_new_enemy(int x, int y, t_game *game)
{
	t_enemy		*new_enemy;
	t_list		*new_element;

	if (!(new_enemy = create_new_enemy(x, y)))
		return (ERROR_MALLOC);
	if (!(new_element = ft_lstnew(new_enemy)))
	{
		free(new_enemy);
		return (ERROR_MALLOC);
	}
	ft_lstadd_front(&(game->en_list), new_element);
	game->config.map[y][x] = '0';
	return (SUCCESS);
}

int				set_enemies(t_game *game)
{
	int			i;
	int			j;
	int			ret_add_new_enemy;

	i = 0;
	while (game->config.map[i])
	{
		j = 0;
		while (game->config.map[i][j])
		{
			if (game->config.map[i][j] == 'X')
			{
				ret_add_new_enemy = add_new_enemy(j, i, game);
				if (SUCCESS != ret_add_new_enemy)
					return (ret_add_new_enemy);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
