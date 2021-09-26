/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:44:31 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 17:02:21 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		**add_new_line_to_map(char *new_line, char **old_map)
{
	char		**new_map;
	size_t		i;

	i = 0;
	while (old_map[i])
		i++;
	if (!(new_map = (char**)malloc(sizeof(*new_map) * (i + 2))))
		return (NULL);
	i = 0;
	while (old_map[i])
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[i++] = new_line;
	new_map[i] = NULL;
	return (new_map);
}

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

int			fill_map(int fd, char *first_line, char ***map)
{
	char	*line;
	int		ret_gnl;
	int		ret_anl;

	if (SUCCESS != (ret_anl = add_new_line(first_line, map)))
		return (ret_anl);
	while (1 == (ret_gnl = get_next_line(fd, &line)))
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
	return (SUCCESS);
}

int			create_map(int fd, char *first_line, char ***map)
{
	if (!(*map = (char**)malloc(sizeof(**map))))
	{
		free(first_line);
		return (ERROR_MALLOC);
	}
	**map = NULL;
	return (fill_map(fd, first_line, map));
}
