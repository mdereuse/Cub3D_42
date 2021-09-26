/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:00:20 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/14 22:16:50 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_first_line(char *line, t_game *game)
{
	if (!*line)
		return (false);
	return (check_config(game));
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

int		set_map(int fd, char *first_line, t_game *game)
{
	char	**map;
	int		ret;

	ret = create_map(fd, first_line, &map);
	if (SUCCESS != ret)
		return (ret);
	game->config.map = map;
	game->clean_check.map = true;
	if (empty_lines(game->config.map))
		return (ERROR_EMPTY_LINES);
	if (SUCCESS != (ret = repare_map(game->config.map)))
		return (ret);
	if (SUCCESS != (ret = check_map(game->config.map)))
		return (ret);
	return (SUCCESS);
}
