/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pattern_config.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:39:41 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/09 13:19:34 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		check_pattern_resolution(char *line)
{
	size_t	i;
	size_t	count_width;
	size_t	count_height;

	i = 0;
	count_width = 0;
	count_height = 0;
	while (line[i] && line[i] != ' ')
		i++;
	skip_spaces(line, &i);
	i += (line[i] && line[i] == '-');
	while (line[i] && ft_isdigit(line[i]))
	{
		count_width++;
		i++;
	}
	skip_spaces(line, &i);
	i += (line[i] && line[i] == '-');
	while (line[i] && ft_isdigit(line[i]))
	{
		count_height++;
		i++;
	}
	skip_spaces(line, &i);
	return (!(bool)line[i] && (bool)count_width && (bool)count_height);
}

bool		check_pattern_texture(char *line)
{
	size_t	i;
	size_t	count_char;

	i = 0;
	count_char = 0;
	while (line[i] && line[i] != ' ')
		i++;
	skip_spaces(line, &i);
	while (line[i] && line[i] != ' ')
	{
		count_char++;
		i++;
	}
	skip_spaces(line, &i);
	return (!(bool)line[i] && (bool)count_char);
}

static void	check_color(char *line, size_t *i, size_t *count_color)
{
	if (line[*i] && line[*i] == '-')
		(*i)++;
	while (line[*i] && ft_isdigit(line[*i]))
	{
		(*count_color)++;
		(*i)++;
	}
}

bool		check_pattern_color(char *line)
{
	size_t	i;
	size_t	count_r;
	size_t	count_g;
	size_t	count_b;

	i = 0;
	count_r = 0;
	count_g = 0;
	count_b = 0;
	while (line[i] && line[i] != ' ')
		i++;
	skip_spaces(line, &i);
	check_color(line, &i, &count_r);
	if (!skip_coma(line, &i))
		return (false);
	check_color(line, &i, &count_g);
	if (!skip_coma(line, &i))
		return (false);
	check_color(line, &i, &count_b);
	skip_spaces(line, &i);
	return (!(bool)line[i] && (bool)count_r && (bool)count_g && (bool)count_b);
}
