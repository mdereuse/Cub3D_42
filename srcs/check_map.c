/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:29:34 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/08 07:44:26 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_map_chars(char **map)
{
	size_t	i;
	size_t	j;
	int		count_player;

	i = 0;
	count_player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_in_set(map[i][j], " 012NSEW"))
				return (ERROR_CHAR_MAP);
			if (is_in_set(map[i][j], "NSEW"))
				count_player++;
			j++;
		}
		i++;
	}
	return (count_player == 1 ? SUCCESS : ERROR_PLAYER_MAP);
}

static int		check_map_closed(char **map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != ' ' && map[i][j] != '1')
				&& (j == 0
					|| !map[i][j + 1]
					|| i == 0
					|| !map[i + 1]
					|| map[i][j - 1] == ' '
					|| map[i][j + 1] == ' '
					|| map[i - 1][j] == ' '
					|| map[i + 1][j] == ' '))
				return (ERROR_OPEN_MAP);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int				check_map(char **map)
{
	int		ret_check_map_chars;
	int		ret_check_map_closed;

	if (SUCCESS != (ret_check_map_closed = check_map_closed(map)))
		return (ret_check_map_closed);
	if (SUCCESS != (ret_check_map_chars = check_map_chars(map)))
		return (ret_check_map_chars);
	return (SUCCESS);
}
