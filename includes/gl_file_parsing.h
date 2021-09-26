/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_file_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:32:14 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 18:25:42 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_FILE_PARSING_H
# define GL_FILE_PARSING_H

# include "cub3d.h"

typedef int			(*t_parsing_fct)(t_game*, char*);

typedef struct		s_parsing
{
	char			*pattern;
	t_parsing_fct	fct;
}					t_parsing;

const t_parsing		g_parsing_tab[] =
{
	{"R ", &set_resolution},
	{"F ", &set_floor_color},
	{"C ", &set_ceiling_color},
	{"NO ", &set_no_texture},
	{"SO ", &set_so_texture},
	{"WE ", &set_we_texture},
	{"EA ", &set_ea_texture},
	{"S ", &set_sp_texture},
	{NULL, NULL}
};

#endif
