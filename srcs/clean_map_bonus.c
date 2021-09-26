/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:28:41 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:36:13 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	clean_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clean_maps(char ***maps)
{
	size_t	i;

	i = 0;
	while (maps[i])
	{
		clean_map(maps[i]);
		i++;
	}
	free(maps);
}

void	clean_map_and_line(char *line, char **map)
{
	free(line);
	clean_map(map);
}

void	clean_map_and_maps(char **map, char ***maps)
{
	clean_map(map);
	clean_maps(maps);
}
