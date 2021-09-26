/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:40:57 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/08 07:46:57 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		main(int argc, char **argv)
{
	t_game		game;
	int			save;

	initialize_game(&game);
	save = (argc == 3 && !ft_strncmp(argv[2], "--save", ft_strlen(argv[2])));
	if (argc != 2 + save)
		quit_failure(ERROR_NB_ARGS, &game);
	if (!file_is_valid(argv[1]))
		quit_failure(ERROR_INVALID_FILE, &game);
	set_game(&game, argv[1]);
	generate_screen(&game);
	push_screen_and_shadow(&game);
	if (save)
		screenshot(game);
	set_window(&game);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.real_screen.id, 0,
																			0);
	mlx_hook(game.win_ptr, EVENT_EXIT, (1L << 17), &quit_hook, &game);
	mlx_hook(game.win_ptr, EVENT_KEY_PRESS, (1L << 0), &key_press, &game);
	mlx_hook(game.win_ptr, EVENT_KEY_RELEASE, (1L << 1), &key_release, &game);
	mlx_loop_hook(game.mlx_ptr, &main_loop, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
