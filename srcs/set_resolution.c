/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:53:42 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:36:09 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pick_resolution(int width, int height, t_game *game)
{
	game->config.resolution.height = fmin(height,
			game->config.max_resolution.height);
	game->config.resolution.width = fmin(width,
			game->config.max_resolution.width);
}

static int	atoi_resolution(char *line, size_t *i)
{
	int		resolution;
	int		neg;

	resolution = 0;
	neg = (line[*i] && line[*i] == '-') ? -1 : 1;
	*i += (line[*i] && line[*i] == '-');
	while (line[*i] && ft_isdigit(line[*i]))
		resolution = resolution * 10 + line[(*i)++] - '0';
	resolution *= neg;
	return (resolution);
}

int			set_resolution(t_game *game, char *line)
{
	size_t			i;
	int				height;
	int				width;

	if (!check_pattern_resolution(line))
		return (ERROR_PATTERN_CONFIG);
	if (game->config.config_check.resolution)
		return (ERROR_DOUBLE_CONFIG);
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	skip_spaces(line, &i);
	width = atoi_resolution(line, &i);
	skip_spaces(line, &i);
	height = atoi_resolution(line, &i);
	if (height <= 0 || width <= 0)
		return (ERROR_RESO_CONFIG);
	pick_resolution(width, height, game);
	game->config.config_check.resolution = true;
	return (SUCCESS);
}
