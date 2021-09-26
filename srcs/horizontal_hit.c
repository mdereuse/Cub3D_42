/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:57:16 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 19:14:05 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	find_first_hit_pos(double ray_angle, t_player player)
{
	t_pos	hit;

	if (ray_angle > 0 && ray_angle < M_PI)
		hit.y = round_down_bs_mul(player.pos.y);
	else
		hit.y = round_up_bs_mul(player.pos.y);
	hit.x = player.pos.x + (player.pos.y - hit.y) / tan(ray_angle);
	return (hit);
}

static int		check_wall_loop(t_wall_hit *hit, t_ray_cast *ray_cast,
																t_game *game)
{
	double		delta_x;
	double		delta_y;

	delta_y = ray_cast->angle > 0 && ray_cast->angle < M_PI ?
												BLOC_SIZE * (-1) : BLOC_SIZE;
	delta_x = (-1) * delta_y / tan(ray_cast->angle);
	while (!is_wall_corr(hit->pos, ray_cast->angle, game))
	{
		hit->pos.x += delta_x;
		hit->pos.y += delta_y;
		if (hit->pos.x <= 0 || hit->pos.x >= game->config.x_max
			|| hit->pos.y <= 0 || hit->pos.y >= game->config.y_max
			|| is_empty_space_corr(hit->pos, ray_cast->angle, game))
			return (ERROR_BLACK);
		if (is_sprite_corr(hit->pos, ray_cast->angle, game)
			&& ERROR_MALLOC == handle_sprite(hit->pos, ray_cast, game))
			return (ERROR_MALLOC);
	}
	if (hit->pos.x <= 0 || hit->pos.x >= game->config.x_max
			|| hit->pos.y <= 0 || hit->pos.y >= game->config.y_max)
		return (ERROR_BLACK);
	return (SUCCESS);
}

int				find_horizontal_hit(t_wall_hit *hit, t_ray_cast *ray_cast,
																t_game *game)
{
	int		ret;

	if (ray_cast->angle == 0 || ray_cast->angle == M_PI)
		return (ERROR_BLACK);
	hit->pos = find_first_hit_pos(ray_cast->angle, game->player);
	if (hit->pos.x <= 0 || hit->pos.x >= game->config.x_max
		|| hit->pos.y <= 0 || hit->pos.y >= game->config.y_max
		|| is_empty_space_corr(hit->pos, ray_cast->angle, game))
		return (ERROR_BLACK);
	if (is_sprite_corr(hit->pos, ray_cast->angle, game)
		&& ERROR_MALLOC == handle_sprite(hit->pos, ray_cast, game))
		return (ERROR_MALLOC);
	if (SUCCESS != (ret = check_wall_loop(hit, ray_cast, game)))
		return (ret);
	hit->wall_type = ray_cast->angle > 0 && ray_cast->angle < M_PI ?
																NORTH : SOUTH;
	hit->dist = get_dist_hit_hor(hit->pos, ray_cast->angle, game->player);
	return (SUCCESS);
}
