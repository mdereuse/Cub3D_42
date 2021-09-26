/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 00:18:25 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 19:13:56 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	find_first_hit_pos(double ray_angle, t_player player)
{
	t_pos	hit;

	if (ray_angle > M_PI / 2 && ray_angle < 3 * M_PI / 2)
		hit.x = round_down_bs_mul(player.pos.x);
	else
		hit.x = round_up_bs_mul(player.pos.x);
	hit.y = player.pos.y + (player.pos.x - hit.x) * tan(ray_angle);
	return (hit);
}

static int		check_wall_loop(t_wall_hit *hit, t_ray_cast *ray_cast,
																t_game *game)
{
	double		delta_x;
	double		delta_y;

	delta_x = ray_cast->angle > M_PI / 2 && ray_cast->angle < 3 * M_PI / 2 ?
												BLOC_SIZE * (-1) : BLOC_SIZE;
	delta_y = (-1) * delta_x * tan(ray_cast->angle);
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

int				find_vertical_hit(t_wall_hit *hit, t_ray_cast *ray_cast,
																t_game *game)
{
	int		ret;

	if (ray_cast->angle == M_PI / 2 || ray_cast->angle == 3 * M_PI / 2)
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
	hit->wall_type = ray_cast->angle > M_PI / 2 && ray_cast->angle < 3
													* M_PI / 2 ? WEST : EAST;
	hit->dist = get_dist_hit_ver(hit->pos, ray_cast->angle, game->player);
	return (SUCCESS);
}
