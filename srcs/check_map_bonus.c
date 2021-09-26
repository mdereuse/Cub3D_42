/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:26:50 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/08 07:38:40 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

size_t	get_charset_size(t_game *game)
{
	size_t	size;

	size = 8;
	if (game->bonus.bonus)
		size++;
	if (game->bonus.trap)
		size++;
	if (game->bonus.obstacle)
		size++;
	if (game->bonus.door)
		size += 2;
	if (game->bonus.enemy)
		size++;
	return (size + 1);
}

char	*get_charset(t_game *game)
{
	char		*charset;
	const char	*charset_default = " 012NSWE";
	size_t		i;

	if (!(charset = (char*)malloc(sizeof(*charset) * get_charset_size(game))))
		return (NULL);
	ft_strlcpy(charset, charset_default, get_charset_size(game));
	i = 8;
	if (game->bonus.bonus)
		charset[i++] = '3';
	if (game->bonus.trap)
		charset[i++] = '4';
	if (game->bonus.obstacle)
		charset[i++] = '5';
	if (game->bonus.door)
	{
		charset[i++] = 'D';
		charset[i++] = 'O';
	}
	if (game->bonus.enemy)
		charset[i++] = 'X';
	charset[i] = '\0';
	return (charset);
}

int		check_map_chars(char **map, t_game *game)
{
	size_t	i;
	size_t	j;
	int		count_player;
	char	*charset;

	if (!(charset = get_charset(game)))
		return (ERROR_MALLOC);
	i = 0;
	count_player = 0;
	while (map[i++])
	{
		j = 0;
		while (map[i - 1][j++])
		{
			if (!is_in_set(map[i - 1][j - 1], charset))
			{
				free(charset);
				return (ERROR_CHAR_MAP);
			}
			if (is_in_set(map[i - 1][j - 1], "NSEW"))
				count_player++;
		}
	}
	free(charset);
	return (count_player == 1 ? SUCCESS : ERROR_PLAYER_MAP);
}

int		check_map_closed(char **map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != ' ' && map[i][j] != '1')
				&& (j == 0
					|| !map[i][j + 1]
					|| i == 0
					|| !map[i + 1]
					|| map[i][j - 1] == ' '
					|| map[i][j + 1] == ' '
					|| map[i - 1][j] == ' '
					|| map[i + 1][j] == ' '))
				return (ERROR_OPEN_MAP);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int		check_map_doors(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'D' || map[i][j] == 'O')
				&& !((map[i][j - 1] == '1' && map[i][j + 1] == '1')
					|| (map[i - 1][j] == '1' && map[i + 1][j] == '1')))
				return (ERROR_DOOR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
