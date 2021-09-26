/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_4_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:11:31 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:12:18 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char		***add_new_map_to_maps(char **new_map, char ***old_maps)
{
	char	***new_maps;
	size_t	i;

	i = 0;
	while (old_maps[i])
		i++;
	if (!(new_maps = (char***)malloc(sizeof(*new_maps) * (i + 2))))
		return (NULL);
	i = 0;
	while (old_maps[i])
	{
		new_maps[i] = old_maps[i];
		i++;
	}
	new_maps[i++] = new_map;
	new_maps[i] = NULL;
	return (new_maps);
}

size_t		get_max_len_line_map(char **map)
{
	size_t	i;
	size_t	max_len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
		i++;
	}
	return (max_len);
}

void		clean_screen(t_image image)
{
	int		i;
	int		j;

	i = 0;
	while (i < image.height)
	{
		j = 0;
		while (j < image.width)
		{
			*((unsigned char*)(image.data + i
										* image.size_line + j * 4 + 3)) = 255;
			j++;
		}
		i++;
	}
}
