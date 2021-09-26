/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_hit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 04:33:31 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/15 14:25:54 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "gl_enemy_texture_bonus.h"

static t_image	get_enemy_texture(t_enemy *enemy, t_game *game)
{
	int		i;

	i = 0;
	while (g_enemy_texture[i].fct)
	{
		if (enemy->state == g_enemy_texture[i].state)
			return ((*(g_enemy_texture[i].fct))(enemy, game));
		i++;
	}
	return (game->config.en_texture);
}

static t_sp_hit	*create_new_hit(t_enemy *enemy, t_ray_cast *ray_cast,
																t_game *game)
{
	t_sp_hit	*new_hit;
	double		alpha;
	double		beta;
	double		gamma;
	double		tmp;

	if (!(new_hit = (t_sp_hit*)malloc(sizeof(*new_hit))))
		return (NULL);
	new_hit->center_pos = enemy->pos;
	alpha = get_alpha_angle(new_hit->center_pos, game->player);
	beta = convert_angle(alpha - ray_cast->angle);
	gamma = convert_angle(alpha - game->player.orientation);
	tmp = get_dist(game->player.pos, new_hit->center_pos);
	new_hit->center_dist = tmp * cos(alpha - game->player.orientation);
	new_hit->dist = tmp * cos(beta);
	new_hit->sp_size = floor(game->config.thales_coeff / new_hit->center_dist);
	new_hit->center_x = floor(game->config.resolution.width / 2 + 1 - tan(gamma)
			* game->config.dist_screen);
	new_hit->col_coeff = (ray_cast->pix_col - (double)new_hit->center_x
			+ new_hit->sp_size / 2) / new_hit->sp_size;
	new_hit->texture = get_enemy_texture(enemy, game);
	new_hit->enemy = enemy;
	return (new_hit);
}

static int		handle_enemy(t_enemy *enemy, t_ray_cast *ray_cast, t_game *game)
{
	t_sp_hit	*new_hit;
	t_list		*new_element;

	if (!(new_hit = create_new_hit(enemy, ray_cast, game)))
		return (ERROR_MALLOC);
	if (!(new_element = ft_lstnew(new_hit)))
	{
		free(new_hit);
		return (ERROR_MALLOC);
	}
	ft_lstadd_front(&(ray_cast->sp_list), new_element);
	return (SUCCESS);
}

int				check_enemy(t_ray_cast *ray_cast, t_game *game)
{
	t_list		*current;
	t_enemy		*enemy;
	double		delta_x;

	if (!game->bonus.enemy)
		return (SUCCESS);
	current = game->en_list;
	while (current)
	{
		enemy = current->content;
		delta_x = get_dist(game->player.pos, enemy->pos)
			* sin(get_beta_angle(enemy->pos, ray_cast->angle, game->player));
		if (fabs(delta_x) <= BLOC_SIZE / 2
			&& ERROR_MALLOC == handle_enemy(enemy, ray_cast, game))
			return (ERROR_MALLOC);
		current = current->next;
	}
	return (SUCCESS);
}
