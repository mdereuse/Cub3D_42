/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:37:33 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/18 04:51:45 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int				find_hit(t_ray_cast *ray_cast, t_game *game)
{
	t_wall_hit	hor_hit;
	t_wall_hit	ver_hit;
	int			ret_hor_hit;
	int			ret_ver_hit;

	if (out_map_pos(game->player.pos, game))
		return (ERROR_BLACK);
	if (ERROR_MALLOC == check_enemy(ray_cast, game))
		return (ERROR_MALLOC);
	if (is_sprite(game->player.pos, game)
		&& ERROR_MALLOC == handle_sprite(game->player.pos, ray_cast, game))
		return (ERROR_MALLOC);
	ret_ver_hit = find_vertical_hit(&ver_hit, ray_cast, game);
	ret_hor_hit = find_horizontal_hit(&hor_hit, ray_cast, game);
	if (ret_ver_hit == ERROR_MALLOC || ret_hor_hit == ERROR_MALLOC)
		return (ERROR_MALLOC);
	if (SUCCESS == ret_hor_hit && SUCCESS == ret_ver_hit)
		ray_cast->wall_hit = hor_hit.dist <= ver_hit.dist ? hor_hit : ver_hit;
	else if (SUCCESS == ret_hor_hit)
		ray_cast->wall_hit = hor_hit;
	else if (SUCCESS == ret_ver_hit)
		ray_cast->wall_hit = ver_hit;
	else
		return (ERROR_BLACK);
	return (SUCCESS);
}
