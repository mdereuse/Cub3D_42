/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:49:22 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:23:59 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			add_new_line(char *line, char ***map)
{
	char	**tmp;

	tmp = *map;
	if (!(*map = add_new_line_to_map(line, *map)))
	{
		clean_map_and_line(line, tmp);
		return (ERROR_MALLOC);
	}
	free(tmp);
	return (SUCCESS);
}

int			fill_first_map(int fd, char *first_line, char ***map)
{
	char	*line;
	int		ret_gnl;
	int		ret_anl;

	if (SUCCESS != (ret_anl = add_new_line(first_line, map)))
		return (ret_anl);
	while (1 == (ret_gnl = get_next_line(fd, &line)) && !is_map_sep(line))
	{
		if (SUCCESS != (ret_anl = add_new_line(line, map)))
			return (ret_anl);
	}
	if (-1 == ret_gnl)
	{
		clean_map(*map);
		return (ERROR_READING_FILE);
	}
	free(line);
	return (ret_gnl ? KEEP_READING : END_FILE);
}

int			fill_new_map(int fd, char ***map)
{
	char	*line;
	int		ret_gnl;
	int		ret_anl;

	while (1 == (ret_gnl = get_next_line(fd, &line)) && !is_map_sep(line))
	{
		if (SUCCESS != (ret_anl = add_new_line(line, map)))
			return (ret_anl);
	}
	if (-1 == ret_gnl)
	{
		clean_map(*map);
		return (ERROR_READING_FILE);
	}
	free(line);
	return (ret_gnl ? KEEP_READING : END_FILE);
}

int			create_first_map(int fd, char *first_line, char ***map)
{
	if (!(*map = (char**)malloc(sizeof(**map))))
	{
		free(first_line);
		return (ERROR_MALLOC);
	}
	**map = NULL;
	return (fill_first_map(fd, first_line, map));
}

int			create_new_map(int fd, char ***map)
{
	if (!(*map = (char**)malloc(sizeof(**map))))
		return (ERROR_MALLOC);
	**map = NULL;
	return (fill_new_map(fd, map));
}
