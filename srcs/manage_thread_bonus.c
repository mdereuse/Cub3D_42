/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thread_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:53:55 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/08 07:36:59 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	*fct_thread(void *engine_addr)
{
	int			ret;
	int			i;
	t_engine	*engine;

	engine = engine_addr;
	i = 0;
	while (i < ceil(engine->game->config.resolution.width / 4)
			&& engine->pix_col < engine->game->config.resolution.width)
	{
		ret = cast_ray(engine);
		if (ERROR_BLACK == ret)
			pthread_exit((void*)ERROR_BLACK);
		if (ERROR_MALLOC == ret)
			pthread_exit((void*)ERROR_MALLOC);
		engine->angle = convert_angle(engine->angle
											- engine->game->config.delta_rad);
		engine->pix_col++;
		i++;
	}
	pthread_exit((void*)SUCCESS);
}

bool	check_returns_error_malloc(void **ret, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (ret[i] == (void*)ERROR_MALLOC)
			return (true);
		i++;
	}
	return (false);
}

bool	check_returns_error_black(void **ret, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (ret[i] == (void*)ERROR_BLACK)
			return (true);
		i++;
	}
	return (false);
}
