/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:10:59 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:33:26 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_sky(t_ray_cast ray_cast, t_game *game)
{
	int		i;

	i = 0;
	while (i < ray_cast.fst_wall_pix)
	{
		*((unsigned int*)(game->screen.data + 4 * ray_cast.pix_col + i *
						game->screen.size_line)) = game->config.ceiling_color;
		i++;
	}
}

static void	print_floor(t_ray_cast ray_cast, t_game *game)
{
	int		i;
	int		min_i;

	min_i = floor(game->player.eye) + 1;
	i = ray_cast.fst_wall_pix + ray_cast.wall_hit.wall_size >= min_i ?
		ray_cast.fst_wall_pix + ray_cast.wall_hit.wall_size : min_i;
	while (i < game->config.resolution.height)
	{
		*((unsigned int*)(game->screen.data + (4 * ray_cast.pix_col + i *
						game->screen.size_line))) = game->config.floor_color;
		i++;
	}
}

static void	print_wall(t_ray_cast ray_cast, t_game *game)
{
	int			i;

	i = ray_cast.fst_wall_pix >= 0 ? ray_cast.fst_wall_pix : 0;
	while (i < ray_cast.fst_wall_pix + ray_cast.wall_hit.wall_size
			&& i < game->config.resolution.height)
	{
		set_wall_pixel_color(game->screen.data + 4 * ray_cast.pix_col + i *
									game->screen.size_line, ray_cast.wall_hit, i
									- ray_cast.fst_wall_pix, game);
		i++;
	}
}

static void	print_sprite(t_ray_cast ray_cast, t_game *game)
{
	int			i;
	int			limit_up;
	t_list		*current;
	t_sp_hit	*sp_hit;

	current = ray_cast.sp_list;
	while (current)
	{
		sp_hit = current->content;
		limit_up = floor(game->player.eye - (game->config.dist_screen
					* (BLOC_SIZE - game->player.head) / sp_hit->center_dist));
		i = limit_up >= 0 ? limit_up : 0;
		while (i < limit_up + sp_hit->sp_size
				&& i < game->config.resolution.height)
		{
			set_sprite_pixel_color(game->screen.data + 4
								* ray_cast.pix_col + i * game->screen.size_line,
								*sp_hit, i - limit_up, game);
			i++;
		}
		current = current->next;
	}
	ft_lstclear(&(ray_cast.sp_list), free);
}

void		print(t_ray_cast ray_cast, t_game *game)
{
	print_sky(ray_cast, game);
	print_wall(ray_cast, game);
	print_floor(ray_cast, game);
	print_sprite(ray_cast, game);
}
