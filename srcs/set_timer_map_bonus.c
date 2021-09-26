/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_timer_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:51:57 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:26:26 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char		*create_new_line_tm(char *line)
{
	size_t	i;
	char	*new_line;

	if (!(new_line = (char*)malloc(sizeof(*new_line) * ft_strlen(line))))
		return (NULL);
	i = 0;
	while (line[i])
	{
		new_line[i] = 0;
		i++;
	}
	return (new_line);
}

char		**create_timer_map(char **map)
{
	char	**timer_map;
	char	**tmp;
	char	*line;
	size_t	i;

	if (!(timer_map = (char**)malloc(sizeof(*timer_map))))
		return (NULL);
	*timer_map = NULL;
	i = 0;
	while (map[i++])
	{
		if (!(line = create_new_line_tm(map[i - 1])))
		{
			clean_map(timer_map);
			return (NULL);
		}
		tmp = timer_map;
		if (!(timer_map = add_new_line_to_map(line, timer_map)))
		{
			clean_map_and_line(line, tmp);
			return (NULL);
		}
		free(tmp);
	}
	return (timer_map);
}

int			create_timer_maps(char ****maps, t_game *game)
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
		if (!(map = create_timer_map(game->config.maps[i - 1])))
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

int			set_timer_maps(t_game *game)
{
	char	***maps;
	int		ret;

	ret = create_timer_maps(&maps, game);
	if (SUCCESS != ret)
		return (ret);
	game->config.timer_maps = maps;
	game->clean_check.timer_map = true;
	game->config.timer_map = game->config.timer_maps[0];
	return (SUCCESS);
}
