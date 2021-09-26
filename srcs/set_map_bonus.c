/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:48:56 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/14 22:20:35 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			add_new_map(char **map, char ****maps)
{
	char	***tmp;

	tmp = *maps;
	if (!(*maps = add_new_map_to_maps(map, *maps)))
	{
		clean_map_and_maps(map, tmp);
		return (ERROR_MALLOC);
	}
	free(tmp);
	return (SUCCESS);
}

int			fill_maps(int fd, char *first_line, char ****maps)
{
	char	**map;
	int		ret;
	int		ret_anm;

	ret = create_first_map(fd, first_line, &map);
	while (KEEP_READING == ret)
	{
		if (SUCCESS != (ret_anm = add_new_map(map, maps)))
			return (ret_anm);
		ret = create_new_map(fd, &map);
	}
	if (ret < 0)
		return (ret);
	if (SUCCESS != (ret_anm = add_new_map(map, maps)))
		return (ret_anm);
	return (SUCCESS);
}

int			create_maps(int fd, char *first_line, char ****maps)
{
	if (!(*maps = (char***)malloc(sizeof(**maps))))
	{
		free(first_line);
		return (ERROR_MALLOC);
	}
	**maps = NULL;
	return (fill_maps(fd, first_line, maps));
}

int			set_maps(int fd, char *first_line, t_game *game)
{
	char	***maps;
	int		ret;
	size_t	i;

	ret = create_maps(fd, first_line, &maps);
	if (SUCCESS != ret)
		return (ret);
	game->config.maps = maps;
	game->clean_check.map = true;
	i = 0;
	while (game->config.maps[i])
	{
		if (empty_lines(game->config.maps[i]))
			return (ERROR_EMPTY_LINES);
		if (SUCCESS != (ret = repare_map(game->config.maps[i])))
			return (ret);
		if (SUCCESS != (ret = check_map(game->config.maps[i], game)))
			return (ret);
		i++;
	}
	game->config.map = game->config.maps[0];
	return (SUCCESS);
}
