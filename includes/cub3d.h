/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 09:44:12 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:23:01 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include "libft.h"
# include "mlx.h"

# define BUFFER_SIZE 32

# define SUCCESS 0
# define ERROR_NB_ARGS -1
# define ERROR_INVALID_FILE -2
# define ERROR_OPENING_FILE -3
# define ERROR_CLOSING_FILE -4
# define ERROR_READING_FILE -5
# define ERROR_MALLOC -6
# define ERROR_NO_MAP -7
# define ERROR_MAP -8
# define ERROR_EMPTY_LINES -19
# define ERROR_OPEN_MAP -22
# define ERROR_CHAR_MAP -23
# define ERROR_PLAYER_MAP -24
# define ERROR_PATTERN_CONFIG -9
# define ERROR_MISSING_PARAM_CONFIG -10
# define ERROR_PARAM_CONFIG -11
# define ERROR_MLX_INIT -12
# define ERROR_MLX_NEW_WINDOW -13
# define ERROR_MLX_NEW_IMAGE -14
# define ERROR_MLX_SCREEN -15
# define ERROR_COLOR_CONFIG -16
# define ERROR_RESO_CONFIG -17
# define ERROR_DOUBLE_CONFIG -18
# define ERROR_BLACK -20

# define TIME_UNIT 0.5
# define BLOC_SIZE 64
# define FOV 1.0472

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_EXIT 17

# define MOVE_FORWARD 0
# define MOVE_BACKWARD 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3
# define ROT_LEFT 4
# define ROT_RIGHT 5
# define EXIT 6
# define END 7

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_cell
{
	int				x;
	int				y;
}					t_cell;

typedef struct		s_image
{
	void			*id;
	int				width;
	int				height;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_config_check
{
	bool			resolution;
	bool			no_texture;
	bool			so_texture;
	bool			we_texture;
	bool			ea_texture;
	bool			sp_texture;
	bool			floor_color;
	bool			ceiling_color;
}					t_config_check;

typedef struct		s_clean_check
{
	bool			no_texture;
	bool			so_texture;
	bool			we_texture;
	bool			ea_texture;
	bool			sp_texture;
	bool			map;
	bool			mlx_ptr;
	bool			window;
	bool			screen;
}					t_clean_check;

typedef struct		s_resolution
{
	int				width;
	int				height;
}					t_resolution;

typedef struct		s_config
{
	t_resolution	max_resolution;
	t_resolution	min_resolution;
	t_resolution	resolution;
	t_image			no_texture;
	t_image			so_texture;
	t_image			we_texture;
	t_image			ea_texture;
	t_image			sp_texture;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char			**map;
	double			delta_rad;
	double			dist_screen;
	double			thales_coeff;
	double			x_max;
	double			y_max;
	int				x_cell_max;
	int				y_cell_max;
	double			player_speed;
	double			rotation_speed;
	t_config_check	config_check;
}					t_config;

typedef struct		s_player
{
	t_pos			pos;
	double			orientation;
	double			eye;
	double			head;
}					t_player;

typedef struct		s_move
{
	bool			forward;
	bool			backward;
	bool			left;
	bool			right;
}					t_move;

typedef struct		s_rot
{
	bool			left;
	bool			right;
}					t_rot;

typedef enum		e_wall_type
{
	NORTH,
	WEST,
	SOUTH,
	EAST
}					t_wall_type;

typedef struct		s_wall_hit
{
	t_pos			pos;
	t_wall_type		wall_type;
	double			dist;
	double			corr_dist;
	int				wall_size;
}					t_wall_hit;

typedef struct		s_sp_hit
{
	t_pos			pos;
	t_pos			center_pos;
	double			dist;
	double			center_dist;
	double			col_coeff;
	int				sp_size;
	t_image			texture;
}					t_sp_hit;

typedef struct		s_ray_cast
{
	int				pix_col;
	double			angle;
	t_wall_hit		wall_hit;
	t_list			*sp_list;
	int				fst_wall_pix;
}					t_ray_cast;

typedef struct		s_scr_gen
{
	int				pix_col;
	double			angle;
}					t_scr_gen;

typedef void		(*t_loop_fct)();

typedef struct		s_game_param
{
	bool			is_on;
	t_loop_fct		fct;
}					t_game_param;

typedef struct		s_game
{
	t_config		config;
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			screen;
	t_game_param	param[END + 1];
	t_player		player;
	t_clean_check	clean_check;
	t_scr_gen		screen_generator;
}					t_game;

bool				is_in_set(char c, char *set);
double				convert_angle(double angle);
double				round_down_bs_mul(double nb);
double				round_up_bs_mul(double nb);
int					get_color_value(unsigned char r, unsigned char g,
															unsigned char b);
void				skip_spaces(char *line, size_t *index);
bool				skip_coma(char *line, size_t *index);
bool				out_map_pos(t_pos pos, t_game *game);
bool				out_map_cell(t_cell cell, t_game *game);
t_pos				get_center_cell_pos(t_pos pos);
t_pos				get_center_cell_corr(t_pos hit_pos, double angle);
double				get_alpha_angle(t_pos sp_center_pos, t_player player);
double				get_beta_angle(t_pos sp_center_pos, double ray_angle,
															t_player player);
size_t				get_max_len_line_map(char **map);

double				get_dist_hit_ver(t_pos pos, double ray_angle,
															t_player player);
double				get_dist_hit_hor(t_pos pos, double ray_angle,
															t_player player);
double				get_corr_dist(double dist, double ray_angle,
															t_player player);
double				get_dist(t_pos pos1, t_pos pos2);

void				correct_x_y(t_pos pos, double ray_angle, int *x, int *y);
t_cell				get_cell(t_pos pos);
t_cell				get_cell_corr(t_pos pos, double angle);

void				clean_map(char **map);
void				clean_map_and_line(char *line, char **map);
void				clean(t_game *game);

void				quit_failure(int error_code, t_game *game);
void				quit(t_game *game);

int					quit_hook(t_game *game);
int					key_press(int key, t_game *game);
int					key_release(int key, t_game *game);
int					main_loop(t_game *game);

void				screenshot(t_game game);

bool				file_is_valid(char *file);

void				initialize_game(t_game *game);

bool				check_pattern_resolution(char *line);
bool				check_pattern_texture(char *line);
bool				check_pattern_color(char *line);
int					check_map(char **map);

bool				is_map_first_line(char *line, t_game *game);
int					repare_map(char **map);
char				**add_new_line_to_map(char *new_line, char **old_map);
int					add_new_line(char *line, char ***map);
int					fill_map(int fd, char *first_line, char ***map);
int					create_map(int fd, char *first_line, char ***map);
int					set_map(int fd, char *first_line, t_game *game);

bool				check_config(t_game *game);
void				set_config(t_game *game, char *file);

int					set_resolution(t_game *game, char *line);

int					set_floor_color(t_game *game, char *line);
int					set_ceiling_color(t_game *game, char *line);

char				*get_texture_path(char *line);
int					set_texture(t_image *texture, t_game *game, char *line);
int					set_no_texture(t_game *game, char *line);
int					set_so_texture(t_game *game, char *line);
int					set_we_texture(t_game *game, char *line);
int					set_ea_texture(t_game *game, char *line);
int					set_sp_texture(t_game *game, char *line);

void				set_player(t_game *game);

void				set_window(t_game *game);
void				set_game(t_game *game, char *file);

int					generate_screen(t_game *game);

int					cast_ray(t_game *game);

bool				is_empty_space_corr(t_pos pos, double angle, t_game *game);
bool				is_empty_space(t_pos pos, t_game *game);
bool				is_wall_corr(t_pos pos, double ray_angle, t_game *game);
bool				is_sprite_corr(t_pos pos, double ray_angle, t_game *game);
bool				is_sprite(t_pos pos, t_game *game);

int					find_hit(t_ray_cast *ray_cast, t_game *game);

int					find_vertical_hit(t_wall_hit *hit, t_ray_cast *ray_cast,
																t_game *game);
int					find_horizontal_hit(t_wall_hit *hit, t_ray_cast *ray_cast,
																t_game *game);

int					sp_hit_cmp(t_sp_hit *hit1, t_sp_hit *hit2);
void				sort_sp_list(t_list **list, int (*cmp)());
void				remove_if_sp_invalid(t_list **sp_list, t_ray_cast ray_cast);

int					handle_sprite(t_pos hit_pos, t_ray_cast *ray_cast,
																t_game *game);

void				print(t_ray_cast ray_cast, t_game *game);

unsigned int		get_pixel_color(int line, int col, t_image texture,
																t_game *game);
void				set_wall_pixel_color(char *data, t_wall_hit hit, int y,
																t_game *game);
void				set_sprite_pixel_color(char *data, t_sp_hit hit, int y,
																t_game *game);

void				move_forward(t_game *game);
void				move_backward(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);

void				rotation_left(t_game *game);
void				rotation_right(t_game *game);

#endif
