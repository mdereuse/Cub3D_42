/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:51:36 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 22:13:27 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*get_texture_path(char *line)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*texture;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	size = i;
	while (line[size] && line[size] != ' ')
		size++;
	if (!(texture = (char*)malloc(sizeof(*texture) * (size + 1))))
		return (NULL);
	j = 0;
	while (line[i] && line[i] != ' ')
		texture[j++] = line[i++];
	texture[j] = '\0';
	return (texture);
}

int		set_texture(t_image *texture, t_game *game, char *line)
{
	char	*path;

	if (!check_pattern_texture(line))
		return (ERROR_PATTERN_CONFIG);
	if (!(path = get_texture_path(line)))
		return (ERROR_MALLOC);
	if (!(texture->id = mlx_xpm_file_to_image(game->mlx_ptr, path,
									&(texture->width), &(texture->height))))
	{
		free(path);
		return (ERROR_MLX_NEW_IMAGE);
	}
	free(path);
	texture->data = mlx_get_data_addr(texture->id, &(texture->bpp),
									&(texture->size_line), &(texture->endian));
	return (SUCCESS);
}

int		set_no_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.config_check.no_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.no_texture),
																game, line)))
		return (ret_set_texture);
	game->config.config_check.no_texture = true;
	game->clean_check.no_texture = true;
	game->lvl.no_texture = game->config.no_texture;
	return (SUCCESS);
}

int		set_ex_no_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.bonus_check.ex_no_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.ex_no_texture),
																game, line)))
		return (ret_set_texture);
	game->config.bonus_check.ex_no_texture = true;
	game->clean_check.ex_no_texture = true;
	return (SUCCESS);
}

int		set_so_texture(t_game *game, char *line)
{
	int		ret_set_texture;

	if (game->config.config_check.so_texture)
		return (ERROR_DOUBLE_CONFIG);
	if (SUCCESS != (ret_set_texture = set_texture(&(game->config.so_texture),
																game, line)))
		return (ret_set_texture);
	game->config.config_check.so_texture = true;
	game->clean_check.so_texture = true;
	game->lvl.so_texture = game->config.so_texture;
	return (SUCCESS);
}
