/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:49:42 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/14 22:19:55 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	is_map_first_line(char *line)
{
	size_t		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (i > 0);
}

bool	is_map_sep(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '*')
			return (false);
		i++;
	}
	return (i == 3);
}

bool	empty_lines(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (!j)
			return (true);
		i++;
	}
	return (false);
}

int		repare_map(char **map)
{
	size_t	i;
	size_t	j;
	size_t	max_len;
	char	*new_line;

	max_len = get_max_len_line_map(map);
	i = 0;
	while (map[i])
	{
		if (!(new_line = (char*)malloc(sizeof(*new_line) * (max_len + 1))))
			return (ERROR_MALLOC);
		j = 0;
		while (map[i][j])
		{
			new_line[j] = map[i][j];
			j++;
		}
		while (j < max_len)
			new_line[j++] = ' ';
		new_line[j] = '\0';
		free(map[i]);
		map[i] = new_line;
		i++;
	}
	return (SUCCESS);
}
