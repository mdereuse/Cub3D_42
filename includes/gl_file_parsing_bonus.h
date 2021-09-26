/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_file_parsing_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:08:23 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/13 17:35:17 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_FILE_PARSING_BONUS_H
# define GL_FILE_PARSING_BONUS_H

# include "cub3d_bonus.h"

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
	{"FT ", &set_fl_texture},
	{"SB ", &set_sky_texture},
	{"B ", &set_bonus_texture},
	{"T ", &set_trap_texture},
	{"O ", &set_obstacle_texture},
	{"XNO ", &set_ex_no_texture},
	{"XSO ", &set_ex_so_texture},
	{"XWE ", &set_ex_we_texture},
	{"XEA ", &set_ex_ea_texture},
	{"XS ", &set_ex_sp_texture},
	{"XFT ", &set_ex_fl_texture},
	{"XSB ", &set_ex_sky_texture},
	{"XB ", &set_ex_bonus_texture},
	{"XT ", &set_ex_trap_texture},
	{"XO ", &set_ex_obstacle_texture},
	{"HP ", &set_hp_texture},
	{"HPD ", &set_hpd_texture},
	{"GO ", &set_go_texture},
	{"V ", &set_win_texture},
	{"D ", &set_door_texture},
	{"EO ", &set_exit_o_texture},
	{"EC ", &set_exit_c_texture},
	{"W1 ", &set_weapon1_texture},
	{"W2 ", &set_weapon2_texture},
	{"W3 ", &set_weapon3_texture},
	{"W4 ", &set_weapon4_texture},
	{"W5 ", &set_weapon5_texture},
	{"EN ", &set_en_texture},
	{"EH1 ", &set_eh1_texture},
	{"EH2 ", &set_eh2_texture},
	{"ED ", &set_ed_texture},
	{"ES ", &set_es_texture},
	{"EA1 ", &set_ea1_texture},
	{"EA2 ", &set_ea2_texture},
	{"EWU ", &set_ewu_texture},
	{"EWL ", &set_ewl_texture},
	{"EWR ", &set_ewr_texture},
	{"EWM ", &set_ewm_texture},
	{"EB ", &set_eb_texture},
	{"EWA ", &set_ewa_texture},
	{"RWD ", &set_rwd_texture},
	{"RWDI ", &set_rwd_icon_texture},
	{"NMB0 ", &set_nb0_texture},
	{"NMB1 ", &set_nb1_texture},
	{"NMB2 ", &set_nb2_texture},
	{"NMB3 ", &set_nb3_texture},
	{"NMB4 ", &set_nb4_texture},
	{"NMB5 ", &set_nb5_texture},
	{"NMB6 ", &set_nb6_texture},
	{"NMB7 ", &set_nb7_texture},
	{"NMB8 ", &set_nb8_texture},
	{"NMB9 ", &set_nb9_texture},
	{NULL, NULL}
};

#endif
