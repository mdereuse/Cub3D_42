/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:45:23 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:05:15 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	atoi_color(char *line, size_t *i)
{
	int		color;
	int		neg;

	color = 0;
	neg = (line[*i] && line[*i] == '-') ? -1 : 1;
	*i += (line[*i] && line[*i] == '-');
	while (line[*i] && ft_isdigit(line[*i]))
		color = color * 10 + line[(*i)++] - '0';
	color *= neg;
	return (color);
}

static void	set_color(char *line, int *r, int *g, int *b)
{
	size_t		i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	skip_spaces(line, &i);
	*r = atoi_color(line, &i);
	skip_spaces(line, &i);
	if (line[i] == ',')
		i++;
	skip_spaces(line, &i);
	*g = atoi_color(line, &i);
	skip_spaces(line, &i);
	if (line[i] == ',')
		i++;
	skip_spaces(line, &i);
	*b = atoi_color(line, &i);
}

int			set_floor_color(t_game *game, char *line)
{
	int		r;
	int		g;
	int		b;

	if (!check_pattern_color(line))
		return (ERROR_PATTERN_CONFIG);
	if (game->config.config_check.floor_color)
		return (ERROR_DOUBLE_CONFIG);
	set_color(line, &r, &g, &b);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ERROR_COLOR_CONFIG);
	game->config.floor_color.r = r;
	game->config.floor_color.g = g;
	game->config.floor_color.b = b;
	game->config.config_check.floor_color = true;
	return (SUCCESS);
}

int			set_ceiling_color(t_game *game, char *line)
{
	int		r;
	int		g;
	int		b;
	int		rgb;

	if (!check_pattern_color(line))
		return (ERROR_PATTERN_CONFIG);
	if (game->config.config_check.ceiling_color)
		return (ERROR_DOUBLE_CONFIG);
	set_color(line, &r, &g, &b);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ERROR_COLOR_CONFIG);
	rgb = get_color_value(r, g, b);
	game->config.ceiling_color = mlx_get_color_value(game->mlx_ptr, rgb);
	game->config.config_check.ceiling_color = true;
	return (SUCCESS);
}
