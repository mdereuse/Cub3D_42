/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:34:45 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 18:57:31 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "gl_key_param_bonus.h"

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
	if (key == KEY_O)
		activate_door(game);
	else if (key == KEY_P)
		pick_item(game);
	else if (key == KEY_F)
		try_activate_weapon(game);
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

static void	put_screens_to_window(t_game *game)
{
	push_screen_and_shadow(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->real_screen.id,
																	0, 0);
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
	if (game->bonus.enemy)
	{
		remove_if_enemy_dead(&(game->en_list));
		actualize_enemies(game);
	}
	if (!game->lvl.finish && ft_lstsize(game->en_list) == 0)
		game->lvl.finish = true;
	if (game->victory && game->bonus.win_screen)
		return (victory(game));
	if (game->player.dead && game->bonus.hud)
		return (game_over(game));
	if (SUCCESS != (ret = generate_screen(game)))
		quit_failure(ret, game);
	put_screens_to_window(game);
	return (0);
}
