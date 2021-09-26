/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:45:12 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:32:24 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "gl_file_parsing.h"

bool		check_config(t_game *game)
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
			&& !is_map_first_line(line, game))
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
	if (SUCCESS != (set_map_ret = set_map(fd, line, game)))
		return (set_map_ret);
	return (SUCCESS);
}

static void	set_const(t_game *game)
{
	size_t	i;
	size_t	max_len;

	i = 0;
	max_len = 0;
	while (game->config.map[i])
	{
		if (ft_strlen(game->config.map[i]) > max_len)
			max_len = ft_strlen(game->config.map[i]);
		i++;
	}
	game->config.x_max = BLOC_SIZE * max_len;
	game->config.x_cell_max = (int)max_len;
	game->config.y_max = BLOC_SIZE * i;
	game->config.y_cell_max = (int)i;
	game->config.player_speed = 0.1 * BLOC_SIZE;
	game->config.rotation_speed = 0.04;
	game->config.delta_rad = FOV / game->config.resolution.width;
	game->config.dist_screen = game->config.resolution.width
														/ (2 * tan(FOV / 2));
	game->config.thales_coeff = game->config.dist_screen * BLOC_SIZE;
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
	game->config.min_resolution.width = 200;
	game->config.min_resolution.height = floor(game->config.resolution.width
																		/ 4);
}
