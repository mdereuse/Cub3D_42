/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 07:57:32 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:38:36 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "gl_key_param.h"

int			quit_hook(t_game *game)
{
	game->param[EXIT].is_on = true;
	return (0);
}

int			key_press(int key, t_game *game)
{
	int		i;

	i = 0;
	while (g_key_press_param[i].key_code != -1)
	{
		if (key == g_key_press_param[i].key_code)
		{
			game->param[g_key_press_param[i].param_code].is_on = true;
			return (0);
		}
		i++;
	}
	return (0);
}

int			key_release(int key, t_game *game)
{
	int		i;

	i = 0;
	while (g_key_release_param[i].key_code != -1)
	{
		if (key == g_key_release_param[i].key_code)
		{
			game->param[g_key_release_param[i].param_code].is_on = false;
			return (0);
		}
		i++;
	}
	return (0);
}

int			main_loop(t_game *game)
{
	int		i;
	int		ret;

	i = 0;
	while (game->param[i].fct)
	{
		if (game->param[i].is_on)
			(*(game->param[i].fct))(game);
		i++;
	}
	if (SUCCESS != (ret = generate_screen(game)))
		quit_failure(ret, game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->screen.id,
																		0, 0);
	return (0);
}
