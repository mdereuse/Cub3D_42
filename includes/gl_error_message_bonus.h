/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_error_message_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:06:26 by mariedere         #+#    #+#             */
/*   Updated: 2020/03/14 22:28:39 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_ERROR_MESSAGE_BONUS_H
# define GL_ERROR_MESSAGE_BONUS_H

# include "cub3d_bonus.h"

typedef struct			s_error
{
	int					code;
	char				*msg;
}						t_error;

const t_error			g_errors[] =
{
	{ERROR_NB_ARGS, "Wrong number of arguments."},
	{ERROR_INVALID_FILE, "Invalid configuration file."},
	{ERROR_OPENING_FILE, "Error while opening file."},
	{ERROR_CLOSING_FILE, "Error while closing file."},
	{ERROR_READING_FILE, "Error while reading file."},
	{ERROR_MALLOC, "Malloc failed."},
	{ERROR_NO_MAP, "Map was either not found or not recognized."},
	{ERROR_MAP, "Error found in map."},
	{ERROR_EMPTY_LINES, "Empty line found in map."},
	{ERROR_OPEN_MAP, "Map is not closed."},
	{ERROR_CHAR_MAP, "Forbidden character found in map."},
	{ERROR_PLAYER_MAP, "Error found in map : wrong number of players."},
	{ERROR_DOOR, "Error found in map : a door must be between two walls."},
	{ERROR_PATTERN_CONFIG, "Parameter not found or not recognized "
		"(wrong pattern)."},
	{ERROR_MISSING_PARAM_CONFIG, "Missing parameter in configuration file."},
	{ERROR_PARAM_CONFIG, "Forbidden value found in configuration file."},
	{ERROR_RESO_CONFIG, "Forbidden resolution value."},
	{ERROR_COLOR_CONFIG, "Forbidden color value."},
	{ERROR_DOUBLE_CONFIG, "Parameter found several times."},
	{ERROR_MLX_INIT, "Connection with X failed."},
	{ERROR_MLX_NEW_WINDOW, "Failed to open new window."},
	{ERROR_MLX_NEW_IMAGE, "Failed to generate image."},
	{ERROR_MLX_SCREEN, "Failed to generate screen."},
	{ERROR_PTHREAD, "Error with pthread library."},
	{0, NULL}
};

#endif
