/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_hit_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:52:54 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:26:58 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

static bool		is_open_door(t_pos pos, double delta_y,
													double angle, t_game *game)
{
	int		x;
	int		y;
	char	closing;
	double	hit_y;

	correct_x_y(pos, angle, &x, &y);
	closing = game->config.door_map[y][x];
	hit_y = (pos.y + delta_y / 2) - round_down_bs_mul(pos.y + delta_y / 2);
	return (hit_y / (double)BLOC_SIZE >= ((double)closing / 100.0));
}

static void		correct_door_pos(t_wall_hit *hit, double delta_x,
																double delta_y)
{
	hit->pos.x += delta_x / 2;
	hit->pos.y += delta_y / 2;
}

static int		check_wall_loop(t_wall_hit *hit, t_ray_cast *ray_cast,
																t_game *game)
{
	double		delta_x;
	double		delta_y;

	delta_x = ray_cast->angle > M_PI / 2 && ray_cast->angle < 3 * M_PI / 2 ?
												BLOC_SIZE * (-1) : BLOC_SIZE;
	delta_y = (-1) * delta_x * tan(ray_cast->angle);
	while (!is_wall_corr(hit->pos, ray_cast->angle, game)
			&& (!is_door_corr(hit->pos, ray_cast->angle, game)
				|| is_open_door(hit->pos, delta_y, ray_cast->angle, game)))
	{
		hit->pos.x += delta_x;
		hit->pos.y += delta_y;
		if (hit->pos.x <= 0 || hit->pos.x >= game->config.x_max
			|| hit->pos.y <= 0 || hit->pos.y >= game->config.y_max)
			return (ERROR_BLACK);
		if (is_sprite_corr(hit->pos, ray_cast->angle, game)
			&& ERROR_MALLOC == handle_sprite(hit->pos, ray_cast, game))
			return (ERROR_MALLOC);
	}
	if (is_door_corr(hit->pos, ray_cast->angle, game))
		correct_door_pos(hit, delta_x, delta_y);
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
		|| hit->pos.y <= 0 || hit->pos.y >= game->config.y_max)
		return (ERROR_BLACK);
	if (is_sprite_corr(hit->pos, ray_cast->angle, game)
		&& ERROR_MALLOC == handle_sprite(hit->pos, ray_cast, game))
		return (ERROR_MALLOC);
	if (SUCCESS != (ret = check_wall_loop(hit, ray_cast, game)))
		return (ret);
	hit->door = (is_door_corr(hit->pos, ray_cast->angle, game));
	hit->exit_lvl = (is_exit_corr(hit->pos, ray_cast->angle, game));
	hit->wall_type = ray_cast->angle > M_PI / 2 && ray_cast->angle < 3
													* M_PI / 2 ? WEST : EAST;
	hit->dist = get_dist_hit_ver(hit->pos, ray_cast->angle, game->player);
	return (SUCCESS);
}
