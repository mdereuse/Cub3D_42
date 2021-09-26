/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:15:09 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/12 16:34:54 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_sp_hit	*new_sp_hit(t_pos hit_pos, t_ray_cast *ray_cast, t_game *game)
{
	t_sp_hit	*sp_hit;
	double		alpha;
	double		beta;
	double		gamma;
	double		tmp;

	if (!(sp_hit = (t_sp_hit*)malloc(sizeof(*sp_hit))))
		return (NULL);
	sp_hit->center_pos = get_center_cell_corr(hit_pos, ray_cast->angle);
	alpha = get_alpha_angle(sp_hit->center_pos, game->player);
	beta = convert_angle(alpha - ray_cast->angle);
	gamma = convert_angle(alpha - game->player.orientation);
	tmp = get_dist(sp_hit->center_pos, game->player.pos);
	sp_hit->center_dist = tmp * cos(alpha - game->player.orientation);
	sp_hit->dist = tmp * cos(beta);
	sp_hit->sp_size = floor(game->config.thales_coeff / sp_hit->center_dist);
	sp_hit->col_coeff = (ray_cast->pix_col - floor(game->config.resolution.width
				/ 2 + 1 - tan(gamma) * game->config.dist_screen
				- sp_hit->sp_size / 2)) / sp_hit->sp_size;
	sp_hit->texture = game->config.sp_texture;
	return (sp_hit);
}

int				handle_sprite(t_pos hit_pos, t_ray_cast *ray_cast, t_game *game)
{
	t_sp_hit	*sp_hit;
	t_list		*new_element;

	if (!(sp_hit = new_sp_hit(hit_pos, ray_cast, game)))
		return (ERROR_MALLOC);
	if (!(new_element = ft_lstnew(sp_hit)))
	{
		free(new_sp_hit);
		return (ERROR_MALLOC);
	}
	ft_lstadd_front(&(ray_cast->sp_list), new_element);
	return (SUCCESS);
}
