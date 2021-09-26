/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:43:15 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/18 01:34:04 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			cast_ray(t_engine *engine)
{
	t_ray_cast	ray_cast;
	int			ret;

	ray_cast.pix_col = engine->pix_col;
	ray_cast.angle = engine->angle;
	ray_cast.sp_list = NULL;
	if (SUCCESS != (ret = find_hit(&ray_cast, engine->game)))
	{
		ft_lstclear(&(ray_cast.sp_list), free);
		return (ret);
	}
	ray_cast.wall_hit.corr_dist = get_corr_dist(ray_cast.wall_hit.dist,
			ray_cast.angle, engine->game->player);
	ray_cast.wall_hit.wall_size =
		floor(engine->game->config.thales_coeff / ray_cast.wall_hit.corr_dist);
	sort_sp_list(&(ray_cast.sp_list), &sp_hit_cmp);
	remove_if_sp_invalid(&(ray_cast.sp_list), ray_cast);
	pick_and_kick(ray_cast.sp_list, engine);
	ray_cast.fst_wall_pix = floor(engine->game->player.eye
			- (engine->game->config.dist_screen * (BLOC_SIZE
			- engine->game->player.head) / ray_cast.wall_hit.corr_dist));
	print(ray_cast, engine->game);
	return (SUCCESS);
}
