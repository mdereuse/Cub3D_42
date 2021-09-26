/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 23:39:51 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/15 14:27:55 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			cast_ray(t_game *game)
{
	t_ray_cast	ray_cast;
	int			ret;

	ray_cast.pix_col = game->screen_generator.pix_col;
	ray_cast.angle = game->screen_generator.angle;
	ray_cast.sp_list = NULL;
	if (SUCCESS != (ret = find_hit(&ray_cast, game)))
	{
		ft_lstclear(&(ray_cast.sp_list), free);
		return (ret);
	}
	ray_cast.wall_hit.corr_dist = get_corr_dist(ray_cast.wall_hit.dist,
			ray_cast.angle, game->player);
	ray_cast.wall_hit.wall_size =
		floor(game->config.thales_coeff / ray_cast.wall_hit.corr_dist);
	sort_sp_list(&(ray_cast.sp_list), &sp_hit_cmp);
	remove_if_sp_invalid(&(ray_cast.sp_list), ray_cast);
	ray_cast.fst_wall_pix = floor(game->player.eye
			- (game->config.dist_screen * (BLOC_SIZE - game->player.head)
			/ ray_cast.wall_hit.corr_dist));
	print(ray_cast, game);
	return (SUCCESS);
}
