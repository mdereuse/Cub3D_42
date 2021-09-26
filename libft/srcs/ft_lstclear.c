/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdereuse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:17:29 by mdereuse          #+#    #+#             */
/*   Updated: 2019/11/09 03:32:47 by mdereuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_element;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	current_element = *lst;
	while (current_element)
	{
		tmp = current_element;
		current_element = current_element->next;
		(*del)(tmp->content);
		free(tmp);
	}
	*lst = (void*)0;
}
