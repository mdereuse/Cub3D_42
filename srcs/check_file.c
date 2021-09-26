/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:17:24 by mariedere         #+#    #+#             */
/*   Updated: 2019/12/29 16:17:42 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	file_is_valid(char *file)
{
	char		*ext;

	if (!file)
		return (false);
	if (!(ext = ft_strrchr(file, '.')))
		return (false);
	return (!(bool)ft_strncmp(ext, ".cub", ft_strlen(ext)));
}
