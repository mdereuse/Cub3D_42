/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:44:07 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/18 05:11:01 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	black_screen(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->screen.height)
	{
		j = 0;
		while (j < game->screen.width)
		{
			*((unsigned int*)(game->screen.data + 4 * j
											+ game->screen.size_line * i)) = 0;
			j++;
		}
		i++;
	}
}

void		set_engine(int index, t_engine *engine, t_game *game)
{
	engine->game = game;
	engine->pix_col = index * ceil(game->config.resolution.width / 4);
	engine->angle = convert_angle(game->player.orientation + FOV / 2
				- index * (game->config.delta_rad
				* ceil(game->config.resolution.width / 4)));
}

static int	generate_screen_thread(t_game *game)
{
	pthread_t			thread[4];
	void				*ret[4];
	t_engine			engine[4];
	int					i;

	i = 0;
	while (i < 4)
	{
		set_engine(i, engine + i, game);
		if (pthread_create(thread + i, NULL, fct_thread, engine + i) == -1)
			return (ERROR_PTHREAD);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(thread[i], ret + i))
			return (ERROR_PTHREAD);
		i++;
	}
	if (check_returns_error_malloc(ret, 4))
		return (ERROR_MALLOC);
	if (check_returns_error_black(ret, 4))
		return (ERROR_BLACK);
	return (SUCCESS);
}

static int	generate_screen_default(t_game *game)
{
	int			ret;
	t_engine	engine;

	engine.game = game;
	engine.pix_col = 0;
	engine.angle = convert_angle(game->player.orientation + FOV / 2);
	while (engine.pix_col < game->config.resolution.width)
	{
		if (SUCCESS != (ret = cast_ray(&engine)))
			return (ret);
		engine.pix_col++;
		engine.angle = convert_angle(engine.angle - game->config.delta_rad);
	}
	return (SUCCESS);
}

int			generate_screen(t_game *game)
{
	int		ret;

	game->item_option.is_defined = false;
	if (game->config.resolution.width > 4)
		ret = generate_screen_thread(game);
	else
		ret = generate_screen_default(game);
	if (ERROR_BLACK == ret)
		black_screen(game);
	else if (SUCCESS != ret)
		return (ret);
	define_item_to_pick(game);
	return (SUCCESS);
}
