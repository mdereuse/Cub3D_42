/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:45:46 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:33:22 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "gl_file_parsing_bonus.h"

static bool	check_config(t_game *game)
{
	return (game->config.config_check.resolution
			&& game->config.config_check.no_texture
			&& game->config.config_check.so_texture
			&& game->config.config_check.we_texture
			&& game->config.config_check.ea_texture
			&& game->config.config_check.sp_texture
			&& game->config.config_check.floor_color
			&& game->config.config_check.ceiling_color);
}

static int	dispatch_line(t_game *game, char *line)
{
	size_t		i;

	if (!*line)
		return (SUCCESS);
	i = 0;
	while (g_parsing_tab[i].pattern)
	{
		if (!ft_strncmp(line, g_parsing_tab[i].pattern,
										ft_strlen(g_parsing_tab[i].pattern)))
			return (g_parsing_tab[i].fct(game, line));
		i++;
	}
	return (ERROR_PATTERN_CONFIG);
}

static int	parse_file(t_game *game, int fd)
{
	int		gnl_ret;
	int		dispatch_ret;
	int		set_map_ret;
	char	*line;

	while (1 == (gnl_ret = get_next_line(fd, &line))
			&& !is_map_first_line(line))
	{
		dispatch_ret = dispatch_line(game, line);
		free(line);
		if (SUCCESS != dispatch_ret)
			return (dispatch_ret);
	}
	if (-1 == gnl_ret)
		return (ERROR_READING_FILE);
	if (0 == gnl_ret)
	{
		free(line);
		return (ERROR_NO_MAP);
	}
	set_bonus(game);
	if (SUCCESS != (set_map_ret = set_maps(fd, line, game)))
		return (set_map_ret);
	return (SUCCESS);
}

static void	set_auxiliary_maps(t_game *game)
{
	int		door_map_ret;
	int		timer_map_ret;

	door_map_ret = set_door_maps(game);
	if (SUCCESS != door_map_ret)
		quit_failure(door_map_ret, game);
	timer_map_ret = set_timer_maps(game);
	if (SUCCESS != timer_map_ret)
		quit_failure(timer_map_ret, game);
}

void		set_config(t_game *game, char *file)
{
	int		fd;
	int		parse_file_ret;
	int		err;

	mlx_get_screen_size(game->mlx_ptr, &(game->config.max_resolution.width),
			&(game->config.max_resolution.height));
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		err = errno;
		quit_failure(err, game);
	}
	parse_file_ret = parse_file(game, fd);
	if (close(fd) < 0)
	{
		err = errno;
		quit_failure(err, game);
	}
	if (SUCCESS != parse_file_ret)
		quit_failure(parse_file_ret, game);
	if (!check_config(game))
		quit_failure(ERROR_MISSING_PARAM_CONFIG, game);
	set_const(game);
	set_auxiliary_maps(game);
}
