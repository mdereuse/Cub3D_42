/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:21:37 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/15 14:27:48 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				sp_hit_cmp(t_sp_hit *hit1, t_sp_hit *hit2)
{
	return (hit1->dist - hit2->dist);
}

void			sort_sp_list(t_list **list, int (*cmp)())
{
	t_list	*ptr1;
	t_list	*ptr2;
	t_list	*ptr3;
	void	*tmp;

	ptr1 = *list;
	while (ptr1 && ptr1->next)
	{
		ptr2 = *list;
		ptr3 = ptr1;
		while (ptr3->next)
		{
			if (cmp(ptr2->content, ptr2->next->content) < 0)
			{
				tmp = ptr2->content;
				ptr2->content = ptr2->next->content;
				ptr2->next->content = tmp;
			}
			ptr2 = ptr2->next;
			ptr3 = ptr3->next;
		}
		ptr1 = ptr1->next;
	}
}

static bool		check_sp_hit(t_sp_hit *hit, t_ray_cast ray_cast)
{
	return (hit->dist >= 0 && hit->dist < ray_cast.wall_hit.dist);
}

void			remove_if_sp_invalid(t_list **sp_list, t_ray_cast ray_cast)
{
	t_list	*current;
	t_list	*tmp;

	if (!sp_list || !*sp_list)
		return ;
	current = *sp_list;
	while (current && current->next)
	{
		if (!check_sp_hit(current->next->content, ray_cast))
		{
			tmp = current->next;
			current->next = current->next->next;
			ft_lstdelone(tmp, free);
		}
		else
			current = current->next;
	}
	current = *sp_list;
	if (!check_sp_hit(current->content, ray_cast))
	{
		*sp_list = current->next;
		ft_lstdelone(current, free);
	}
}
