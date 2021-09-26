/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:26:14 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:14:34 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	file_is_valid(char *file)
{
	char		*ext;

	if (!file)
		return (false);
	if (!(ext = ft_strrchr(file, '.')))
		return (false);
	return (!(bool)ft_strncmp(ext, ".cub", ft_strlen(ext)));
}
