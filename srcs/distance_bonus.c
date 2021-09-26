/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:31:10 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:21:38 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	get_dist_hit_ver(t_pos pos, double ray_angle, t_player player)
{
	return ((-1) * (player.pos.x - pos.x) / cos(ray_angle));
}

double	get_dist_hit_hor(t_pos pos, double ray_angle, t_player player)
{
	return ((player.pos.y - pos.y) / sin(ray_angle));
}

double	get_corr_dist(double dist, double ray_angle, t_player player)
{
	return (dist * cos(player.orientation - ray_angle));
}

double	get_dist(t_pos pos1, t_pos pos2)
{
	return (sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2)));
}
