/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariedereuse <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:02:25 by mariedere         #+#    #+#             */
/*   Updated: 2020/05/14 22:24:12 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
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
# include <pthread.h>
# include "libft.h"
# include "mlx.h"

# define BUFFER_SIZE 32
# define KEEP_READING 1
# define END_FILE 2

# define DAMAGE 2
# define LIFE 10

# define SUCCESS 0
# define ERROR_NB_ARGS -1
# define ERROR_INVALID_FILE -2
# define ERROR_OPENING_FILE -3
# define ERROR_CLOSING_FILE -4
# define ERROR_READING_FILE -5
# define ERROR_MALLOC -6
# define ERROR_NO_MAP -7
# define ERROR_MAP -8
# define ERROR_EMPTY_LINES -21
# define ERROR_OPEN_MAP -22
# define ERROR_CHAR_MAP -23
# define ERROR_PLAYER_MAP -24
# define ERROR_DOOR -25
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
# define ERROR_PTHREAD -19
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
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_ESC 65307
# define KEY_O 111
# define KEY_P 112
# define KEY_C 99
# define KEY_F 102
# define KEY_SPACE 32
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_EXIT 17

# define MOVE_FORWARD 0
# define MOVE_BACKWARD 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3
# define ROT_LEFT 4
# define ROT_RIGHT 5
# define LOOK_UP 6
# define LOOK_DOWN 7
# define CROUCH 8
# define JUMP 9
# define EXIT 10
# define DOOR 11
# define WEAPON 12
# define END 13

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

typedef struct		s_bonus_check
{
	bool			ex_no_texture;
	bool			ex_so_texture;
	bool			ex_we_texture;
	bool			ex_ea_texture;
	bool			ex_sp_texture;
	bool			ex_fl_texture;
	bool			ex_sky_texture;
	bool			ex_bonus_texture;
	bool			ex_trap_texture;
	bool			ex_obstacle_texture;
	bool			fl_texture;
	bool			sky_texture;
	bool			bonus_texture;
	bool			trap_texture;
	bool			obstacle_texture;
	bool			hp_texture;
	bool			hpd_texture;
	bool			go_texture;
	bool			win_texture;
	bool			door_texture;
	bool			exit_o_texture;
	bool			exit_c_texture;
	bool			w1_texture;
	bool			w2_texture;
	bool			w3_texture;
	bool			w4_texture;
	bool			w5_texture;
	bool			en_texture;
	bool			ewu_texture;
	bool			es_texture;
	bool			ea1_texture;
	bool			ea2_texture;
	bool			eh1_texture;
	bool			eh2_texture;
	bool			ed_texture;
	bool			ewl_texture;
	bool			ewr_texture;
	bool			ewm_texture;
	bool			ewa_texture;
	bool			eb_texture;
	bool			rwd_texture;
	bool			rwd_icon_texture;
	bool			nb0_texture;
	bool			nb1_texture;
	bool			nb2_texture;
	bool			nb3_texture;
	bool			nb4_texture;
	bool			nb5_texture;
	bool			nb6_texture;
	bool			nb7_texture;
	bool			nb8_texture;
	bool			nb9_texture;
}					t_bonus_check;

typedef struct		s_bonus
{
	bool			floor_texture;
	bool			skybox;
	bool			hud;
	bool			bonus;
	bool			trap;
	bool			obstacle;
	bool			door;
	bool			weapon;
	bool			enemy;
	bool			extra_textures;
	bool			win_screen;
}					t_bonus;

typedef struct		s_clean_check
{
	bool			no_texture;
	bool			so_texture;
	bool			we_texture;
	bool			ea_texture;
	bool			sp_texture;
	bool			fl_texture;
	bool			sky_texture;
	bool			bonus_texture;
	bool			trap_texture;
	bool			obstacle_texture;
	bool			ex_no_texture;
	bool			ex_so_texture;
	bool			ex_we_texture;
	bool			ex_ea_texture;
	bool			ex_sp_texture;
	bool			ex_fl_texture;
	bool			ex_sky_texture;
	bool			ex_bonus_texture;
	bool			ex_trap_texture;
	bool			ex_obstacle_texture;
	bool			hp_texture;
	bool			hpd_texture;
	bool			go_texture;
	bool			win_texture;
	bool			door_texture;
	bool			exit_o_texture;
	bool			exit_c_texture;
	bool			w1_texture;
	bool			w2_texture;
	bool			w3_texture;
	bool			w4_texture;
	bool			w5_texture;
	bool			en_texture;
	bool			ewu_texture;
	bool			es_texture;
	bool			ea1_texture;
	bool			ea2_texture;
	bool			eh1_texture;
	bool			eh2_texture;
	bool			ed_texture;
	bool			ewl_texture;
	bool			ewr_texture;
	bool			ewm_texture;
	bool			ewa_texture;
	bool			eb_texture;
	bool			rwd_texture;
	bool			rwd_icon_texture;
	bool			nb0_texture;
	bool			nb1_texture;
	bool			nb2_texture;
	bool			nb3_texture;
	bool			nb4_texture;
	bool			nb5_texture;
	bool			nb6_texture;
	bool			nb7_texture;
	bool			nb8_texture;
	bool			nb9_texture;
	bool			map;
	bool			door_map;
	bool			timer_map;
	bool			mlx_ptr;
	bool			window;
	bool			screen;
	bool			real_screen;
	bool			hud;
	bool			weapon_screen;
}					t_clean_check;

typedef struct		s_resolution
{
	int				width;
	int				height;
}					t_resolution;

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

typedef struct		s_w_anim
{
	int				time;
	t_image			picture;
}					t_w_anim;

typedef struct		s_number
{
	char			alpha;
	t_image			image;
}					t_number;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

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
	t_image			fl_texture;
	t_image			sky_texture;
	t_image			bonus_texture;
	t_image			trap_texture;
	t_image			obstacle_texture;
	t_image			ex_no_texture;
	t_image			ex_so_texture;
	t_image			ex_we_texture;
	t_image			ex_ea_texture;
	t_image			ex_sp_texture;
	t_image			ex_fl_texture;
	t_image			ex_sky_texture;
	t_image			ex_bonus_texture;
	t_image			ex_trap_texture;
	t_image			ex_obstacle_texture;
	t_image			hp_texture;
	t_image			hpd_texture;
	t_image			go_texture;
	t_image			win_texture;
	t_image			door_texture;
	t_image			exit_o_texture;
	t_image			exit_c_texture;
	t_image			w1_texture;
	t_image			w2_texture;
	t_image			w3_texture;
	t_image			w4_texture;
	t_image			w5_texture;
	t_image			en_texture;
	t_image			ewu_texture;
	t_image			es_texture;
	t_image			ea1_texture;
	t_image			ea2_texture;
	t_image			eh1_texture;
	t_image			eh2_texture;
	t_image			ed_texture;
	t_image			ewl_texture;
	t_image			ewr_texture;
	t_image			ewm_texture;
	t_image			eb_texture;
	t_image			ewa_texture;
	t_image			rwd_texture;
	t_image			rwd_icon_texture;
	t_image			nb0_texture;
	t_image			nb1_texture;
	t_image			nb2_texture;
	t_image			nb3_texture;
	t_image			nb4_texture;
	t_image			nb5_texture;
	t_image			nb6_texture;
	t_image			nb7_texture;
	t_image			nb8_texture;
	t_image			nb9_texture;
	t_color			floor_color;
	unsigned int	ceiling_color;
	char			***maps;
	char			***door_maps;
	char			***timer_maps;
	char			**map;
	char			**door_map;
	char			**timer_map;
	double			delta_rad;
	double			dist_screen;
	double			thales_coeff;
	double			x_max;
	double			y_max;
	int				x_cell_max;
	int				y_cell_max;
	int				x_weapon;
	int				y_weapon;
	int				size_weapon;
	int				heart_size;
	int				x_life_bar;
	int				y_life_bar;
	int				x_rwd_icon;
	int				y_rwd_icon;
	int				rwd_icon_size;
	int				x_rwd_nmb;
	int				y_rwd_nmb;
	int				nmb_size;
	int				x_message;
	int				y_message;
	int				message_width;
	int				message_height;
	int				waking_up_time;
	int				surprised_time;
	int				surprised_cling;
	int				walking_cling;
	int				fst_attack_time;
	int				attack_time;
	int				breathing_time;
	int				hurt_time;
	int				hurt_cling;
	int				dying_time;
	int				wp_anim_time;
	int				glass_limit;
	double			view_distance;
	double			pick_distance;
	double			weapon_distance;
	double			critical_distance;
	double			assault_distance;
	int				hit_box;
	int				crouch_height;
	double			player_speed;
	double			rotation_speed;
	int				crouch_speed;
	int				jumping_u_speed;
	int				jumping_d_speed;
	int				look_speed;
	int				door_speed;
	t_w_anim		weapon_animation[6];
	t_number		number[10];
	t_bonus_check	bonus_check;
	t_config_check	config_check;
}					t_config;

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

typedef enum		e_posture
{
	STANDING_UP,
	STOOD_UP,
	CROUCHING,
	CROUCHED,
	JUMPING_UP,
	JUMPING_DOWN
}					t_posture;

typedef struct		s_player
{
	t_pos			pos;
	double			orientation;
	double			eye;
	double			head;
	t_posture		posture;
	int				life;
	bool			dead;
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
	bool			door;
	bool			exit_lvl;
}					t_wall_hit;

typedef enum		e_state
{
	WAITING,
	WOKE_UP,
	SURPRISED,
	WALKING,
	ATTACKING,
	BREATHING,
	HURT,
	DYING,
	DEAD,
	PICKED
}					t_state;

typedef struct		s_enemy
{
	t_pos			pos;
	double			orientation;
	int				life;
	t_state			state;
	int				timer;
}					t_enemy;

typedef struct		s_sp_hit
{
	t_pos			pos;
	t_pos			center_pos;
	double			dist;
	double			center_dist;
	int				center_x;
	double			col_coeff;
	int				sp_size;
	t_image			texture;
	t_enemy			*enemy;
}					t_sp_hit;

typedef struct		s_item_option
{
	bool			is_defined;
	t_sp_hit		sp_hit;
}					t_item_option;

typedef struct		s_item_target
{
	bool			is_defined;
	t_enemy			*enemy;
	t_pos			pos;
}					t_item_target;

typedef struct		s_ray_cast
{
	int				pix_col;
	double			angle;
	t_wall_hit		wall_hit;
	t_list			*sp_list;
	int				fst_wall_pix;
}					t_ray_cast;

typedef void		(*t_loop_fct)();

typedef struct		s_game_param
{
	bool			is_on;
	t_loop_fct		fct;
}					t_game_param;

typedef struct		s_lvl
{
	int				number;
	bool			finish;
	t_image			no_texture;
	t_image			so_texture;
	t_image			we_texture;
	t_image			ea_texture;
	t_image			sp_texture;
	t_image			fl_texture;
	t_image			sky_texture;
	t_image			bonus_texture;
	t_image			trap_texture;
	t_image			obstacle_texture;
}					t_lvl;

typedef struct		s_game
{
	t_config		config;
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			screen;
	t_image			real_screen;
	t_image			hud;
	t_image			weapon_screen;
	t_game_param	param[END + 1];
	t_player		player;
	t_list			*en_list;
	t_enemy			*victim;
	bool			attack;
	int				weapon_timer;
	int				rwd_count;
	t_item_option	item_option;
	t_item_target	item_target;
	t_lvl			lvl;
	bool			victory;
	t_clean_check	clean_check;
	t_bonus			bonus;
	pthread_mutex_t	mutex;
}					t_game;

typedef struct		s_engine
{
	int				pix_col;
	double			angle;
	t_game			*game;
}					t_engine;

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
char				**add_new_line_to_map(char *new_line, char **old_map);
char				***add_new_map_to_maps(char **new_map, char ***old_maps);
void				clean_screen(t_image image);

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
t_cell				get_up_cell(t_cell cell);
t_cell				get_down_cell(t_cell cell);
t_cell				get_left_cell(t_cell cell);
t_cell				get_right_cell(t_cell cell);

void				clean_1(t_game *game);
void				clean_2(t_game *game);
void				clean_3(t_game *game);
void				clean_4(t_game *game);
void				clean_5(t_game *game);
void				clean(t_game *game);
void				clean_maps(char ***map);
void				clean_map(char **map);
void				clean_map_and_line(char *line, char **map);
void				clean_map_and_maps(char **map, char ***maps);

void				quit_failure(int error_code, t_game *game);
void				quit(t_game *game);

int					quit_hook(t_game *game);
int					key_press(int key, t_game *game);
int					key_release(int key, t_game *game);
int					main_loop(t_game *game);

void				screenshot(t_game game);

bool				file_is_valid(char *file);

void				initialize_clean_check(t_game *game);
void				initialize_config_check(t_game *game);
void				initialize_bonus_check(t_game *game);
void				initialize_params(t_game *game);
void				initialize_bonus(t_game *game);
void				initialize_game(t_game *game);

bool				check_pattern_resolution(char *line);
bool				check_pattern_texture(char *line);
bool				check_pattern_color(char *line);
size_t				get_charset_size(t_game *game);
char				*get_charset(t_game *game);
int					check_map_chars(char **map, t_game *game);
int					check_map_closed(char **map);
int					check_map_doors(char **map);
int					check_map(char **map, t_game *game);

bool				is_map_first_line(char *line);
bool				is_map_sep(char *line);
bool				empty_lines(char **map);
int					repare_map(char **map);
int					add_new_line(char *line, char ***map);
int					fill_first_map(int fd, char *first_line, char ***map);
int					fill_new_map(int fd, char ***map);
int					create_first_map(int fd, char *first_line, char ***map);
int					create_new_map(int fd, char ***map);
int					add_new_map(char **map, char ****maps);
int					fill_maps(int fd, char *first_line, char ****maps);
int					create_maps(int fd, char *first_line, char ****maps);
int					set_maps(int fd, char *first_line, t_game *game);

int					set_door_maps(t_game *game);

int					set_timer_maps(t_game *game);

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
int					set_fl_texture(t_game *game, char *line);
int					set_sky_texture(t_game *game, char *line);
int					set_hp_texture(t_game *game, char *line);
int					set_hpd_texture(t_game *game, char *line);
int					set_bonus_texture(t_game *game, char *line);
int					set_trap_texture(t_game *game, char *line);
int					set_obstacle_texture(t_game *game, char *line);
int					set_door_texture(t_game *game, char *line);
int					set_weapon1_texture(t_game *game, char *line);
int					set_weapon2_texture(t_game *game, char *line);
int					set_weapon3_texture(t_game *game, char *line);
int					set_weapon4_texture(t_game *game, char *line);
int					set_weapon5_texture(t_game *game, char *line);
int					set_en_texture(t_game *game, char *line);
int					set_eh1_texture(t_game *game, char *line);
int					set_eh2_texture(t_game *game, char *line);
int					set_ed_texture(t_game *game, char *line);
int					set_es_texture(t_game *game, char *line);
int					set_ea1_texture(t_game *game, char *line);
int					set_ea2_texture(t_game *game, char *line);
int					set_ewl_texture(t_game *game, char *line);
int					set_ewr_texture(t_game *game, char *line);
int					set_ewm_texture(t_game *game, char *line);
int					set_ewu_texture(t_game *game, char *line);
int					set_eb_texture(t_game *game, char *line);
int					set_ewa_texture(t_game *game, char *line);
int					set_rwd_texture(t_game *game, char *line);
int					set_rwd_icon_texture(t_game *game, char *line);
int					set_nb0_texture(t_game *game, char *line);
int					set_nb1_texture(t_game *game, char *line);
int					set_nb2_texture(t_game *game, char *line);
int					set_nb3_texture(t_game *game, char *line);
int					set_nb4_texture(t_game *game, char *line);
int					set_nb5_texture(t_game *game, char *line);
int					set_nb6_texture(t_game *game, char *line);
int					set_nb7_texture(t_game *game, char *line);
int					set_nb8_texture(t_game *game, char *line);
int					set_nb9_texture(t_game *game, char *line);
int					set_ex_no_texture(t_game *game, char *line);
int					set_ex_so_texture(t_game *game, char *line);
int					set_ex_we_texture(t_game *game, char *line);
int					set_ex_ea_texture(t_game *game, char *line);
int					set_ex_sp_texture(t_game *game, char *line);
int					set_ex_fl_texture(t_game *game, char *line);
int					set_ex_sky_texture(t_game *game, char *line);
int					set_ex_bonus_texture(t_game *game, char *line);
int					set_ex_trap_texture(t_game *game, char *line);
int					set_ex_obstacle_texture(t_game *game, char *line);
int					set_win_texture(t_game *game, char *line);
int					set_go_texture(t_game *game, char *line);
int					set_exit_o_texture(t_game *game, char *line);
int					set_exit_c_texture(t_game *game, char *line);

void				set_x_max(t_game *game);
void				set_y_max(t_game *game);
void				set_const(t_game *game);

void				set_screen_image(t_game *game);
void				set_hud_image(t_game *game);
void				set_weapon_image(t_game *game);

void				set_bonus(t_game *game);

int					set_enemies(t_game *game);

void				set_player(t_game *game);

void				set_window(t_game *game);
void				set_game(t_game *game, char *file);

void				generate_life_bar(t_game *game);

void				generate_reward_count(t_game *game);

void				generate_hud(t_game *game);

void				generate_weapon(t_image texture, t_game *game);

int					generate_screen(t_game *game);

void				*fct_thread(void *game);
bool				check_returns_error_malloc(void **ret, int size);
bool				check_returns_error_black(void **ret, int size);

void				get_closest_sprite(t_list *sp_list, t_game *game);
void				get_closest_enemy(t_list *sp_list, t_game *game);
void				pick_and_kick(t_list *sp_list, t_engine *engine);
void				define_item_to_pick(t_game *game);

int					cast_ray(t_engine *engine);

bool				is_exit_corr(t_pos pos, double angle, t_game *game);
bool				is_door(t_pos pos, t_game *game);
bool				is_door_corr(t_pos pos, double angle, t_game *game);
bool				is_wall_corr(t_pos pos, double ray_angle, t_game *game);
bool				is_wall_door_corr(t_pos pos, double angle, t_game *game);
bool				is_sprite_corr(t_pos pos, double ray_angle, t_game *game);
bool				is_sprite(t_pos pos, t_game *game);
bool				is_obstacle(t_pos pos, t_game *game);

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

int					check_enemy(t_ray_cast *ray_cast, t_game *game);

void				print(t_ray_cast ray_cast, t_game *game);

int					get_pixel_rgb_color(int line, int col, t_image texture);
int					get_pixel_rgb_color_shdw(double opacity, int line, int col,
															t_image texture);
double				get_delta_x_floor(double dist, t_ray_cast ray_cast,
																t_game *game);
double				get_delta_y_floor(double dist, t_ray_cast ray_cast,
																t_game *game);
double				get_opacity(double dist, t_game *game);
unsigned int		get_sky_pixel_color(int i, t_ray_cast ray_cast,
																t_game *game);
unsigned int		get_door_pixel_color(t_wall_hit hit, int y, t_game *game);
unsigned int		get_wall_pixel_color(t_wall_hit hit, int y, t_game *game);
unsigned int		get_floor_pixel_color(double dist, t_ray_cast ray_cast,
																t_game *game);
unsigned int		get_sprite_pixel_color(t_sp_hit hit, int y, t_game *game);
unsigned int		get_floor_color_shdw(double dist, t_game *game);

bool				check_dist_enemies(t_pos pos, t_game *game);
bool				is_new_pos_ok(t_pos pos, double angle, t_game *game);
void				avoid_sprite(t_pos *pos, t_pos sp_pos, double angle,
																t_game *game);

void				move_forward(t_game *game);
void				move_backward(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);

void				rotation_left(t_game *game);
void				rotation_right(t_game *game);
void				look_down(t_game *game);
void				look_up(t_game *game);

void				crouch(t_game *game);
void				jump(t_game *game);
void				activate_door(t_game *game);
void				activate_weapon(t_game *game);
void				try_activate_weapon(t_game *game);

void				damage(t_game *game);
void				recup(t_game *game);
void				pick_item(t_game *game);

void				remove_if_enemy_dead(t_list **en_list);
void				actualize_enemies(t_game *game);

void				being_waiting(t_enemy *enemy, t_game *game);
void				being_awake(t_enemy *enemy, t_game *game);
void				being_walking(t_enemy *enemy, t_game *game);
void				being_surprised(t_enemy *enemy, t_game *game);
void				being_attacking(t_enemy *enemy, t_game *game);
void				being_breathing(t_enemy *enemy, t_game *game);
void				being_hurt(t_enemy *enemy, t_game *game);
void				being_dying(t_enemy *enemy, t_game *game);
void				walk(t_enemy *enemy, t_game *game);

t_image				get_waiting_texture(t_enemy *enemy, t_game *game);
t_image				get_woke_up_texture(t_enemy *enemy, t_game *game);
t_image				get_surprised_texture(t_enemy *enemy, t_game *game);
t_image				get_walking_texture(t_enemy *enemy, t_game *game);
t_image				get_attacking_texture(t_enemy *enemy, t_game *game);
t_image				get_breathing_texture(t_enemy *enemy, t_game *game);
t_image				get_hurt_texture(t_enemy *enemy, t_game *game);
t_image				get_dying_texture(t_enemy *enemy, t_game *game);
t_image				get_dead_texture(t_enemy *enemy, t_game *game);
t_image				get_picked_texture(t_enemy *enemy, t_game *game);

void				door_checking(t_game *game);

bool				look_current_cell(t_cell cell, char c, t_game *game);
bool				look_up_cell(t_cell cell, char c, t_game *game);
bool				look_down_cell(t_cell cell, char c, t_game *game);
bool				look_left_cell(t_cell cell, char c, t_game *game);
bool				look_right_cell(t_cell cell, char c, t_game *game);

void				next_lvl(t_game *game);

int					game_over(t_game *game);

int					victory(t_game *game);

void				push_screen_and_shadow(t_game *game);

#endif
