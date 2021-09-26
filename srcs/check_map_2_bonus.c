/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:02:27 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:02:47 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_map(char **map, t_game *game)
{
	int		ret_check_map_chars;
	int		ret_check_map_closed;
	int		ret_check_map_doors;

	if (SUCCESS != (ret_check_map_closed = check_map_closed(map)))
		return (ret_check_map_closed);
	if (SUCCESS != (ret_check_map_chars = check_map_chars(map, game)))
		return (ret_check_map_chars);
	if (SUCCESS != (ret_check_map_doors = check_map_doors(map)))
		return (ret_check_map_doors);
	return (SUCCESS);
}
