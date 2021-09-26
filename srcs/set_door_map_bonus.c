/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_door_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:47:15 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:23:42 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char		*create_new_line_dm(char *line)
{
	size_t	i;
	char	*new_line;

	if (!(new_line = (char*)malloc(sizeof(*new_line) * ft_strlen(line))))
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == 'D' || line[i] == 'O')
			new_line[i] = 100;
		else
			new_line[i] = 0;
		i++;
	}
	return (new_line);
}

char		**create_door_map(char **map)
{
	char	**door_map;
	char	**tmp;
	char	*line;
	size_t	i;

	if (!(door_map = (char**)malloc(sizeof(*door_map))))
		return (NULL);
	*door_map = NULL;
	i = 0;
	while (map[i++])
	{
		if (!(line = create_new_line_dm(map[i - 1])))
		{
			clean_map(door_map);
			return (NULL);
		}
		tmp = door_map;
		if (!(door_map = add_new_line_to_map(line, door_map)))
		{
			clean_map_and_line(line, tmp);
			return (NULL);
		}
		free(tmp);
	}
	return (door_map);
}

int			create_door_maps(char ****maps, t_game *game)
{
	size_t		i;
	char		***tmp;
	char		**map;

	if (!(*maps = (char***)malloc(sizeof(**maps))))
		return (ERROR_MALLOC);
	**maps = NULL;
	i = 0;
	while (game->config.maps[i++])
	{
		if (!(map = create_door_map(game->config.maps[i - 1])))
		{
			clean_maps(*maps);
			return (ERROR_MALLOC);
		}
		tmp = *maps;
		if (!(*maps = add_new_map_to_maps(map, *maps)))
		{
			clean_map(map);
			clean_maps(tmp);
			return (ERROR_MALLOC);
		}
		free(tmp);
	}
	return (SUCCESS);
}

int			set_door_maps(t_game *game)
{
	char	***maps;
	int		ret;

	ret = create_door_maps(&maps, game);
	if (SUCCESS != ret)
		return (ret);
	game->config.door_maps = maps;
	game->clean_check.door_map = true;
	game->config.door_map = game->config.door_maps[0];
	return (SUCCESS);
}
