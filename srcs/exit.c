/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:37:55 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:52:01 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "gl_error_message.h"

void	quit_failure(int error_code, t_game *game)
{
	size_t		i;

	ft_putstr_fd("Error\n", 1);
	if (error_code >= 0)
		ft_putstr_fd(strerror(error_code), 1);
	else
	{
		i = 0;
		while (g_errors[i].code)
		{
			if (g_errors[i].code == error_code)
				ft_putstr_fd(g_errors[i].msg, 1);
			i++;
		}
	}
	ft_putstr_fd("\n", 1);
	clean(game);
	exit(EXIT_FAILURE);
}

void	quit(t_game *game)
{
	clean(game);
	exit(EXIT_SUCCESS);
}
