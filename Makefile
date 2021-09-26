CC = clang
CFLAGS_DFLT = -Wall -Wextra -Werror -I ${INC_DIR} -I ${MLX_DIR} -I ${LIBFT_INC_DIR}
CFLAGS_BONUS = -Wall -Wextra -Werror -O3 -I ${INC_DIR} -I ${MLX_DIR} -I ${LIBFT_INC_DIR}

LDFLAGS_DFLT = -L${LIBFT_DIR} -L${MLX_DIR} -lft -lm -lbsd -lmlx -lXext -lX11
LDFLAGS_BONUS = -L${LIBFT_DIR} -L${MLX_DIR} -lft -lm -lbsd -lmlx -lpthread -lXext -lX11

INC_DIR = ./includes/
SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/
MLX_DIR = ./minilibx/
LIBFT_DIR = ./libft/
LIBFT_INC_DIR = ./libft/includes/

INC_NAME_DFLT = cub3d.h
INC_NAME_BONUS = cub3d_bonus.h
SRCS_NAME_DFLT = main.c\
	   auxiliary.c\
	   auxiliary_2.c\
	   auxiliary_3.c\
	   event.c\
	   set_resolution.c\
	   set_texture.c\
	   set_texture_2.c\
	   set_color.c\
	   set_map.c\
	   set_map_2.c\
	   check_map.c\
	   clean_map.c\
	   check_pattern_config.c\
	   check_file.c\
	   set_config.c\
	   set_player.c\
	   set_game.c\
	   initialize_game.c\
	   move.c\
	   camera.c\
	   cell.c\
	   check_cell.c\
	   hit.c\
	   horizontal_hit.c\
	   vertical_hit.c\
	   sprite_hit.c\
	   sprite_list.c\
	   screen.c\
	   ray_casting.c\
	   print.c\
	   set_pixel_color.c\
	   distance.c\
	   screenshot.c\
	   exit.c\
	   clean.c
SRCS_NAME_BONUS = main_bonus.c\
	   auxiliary_bonus.c\
	   auxiliary_2_bonus.c\
	   auxiliary_3_bonus.c\
	   auxiliary_4_bonus.c\
	   event_bonus.c\
	   set_resolution_bonus.c\
	   set_texture_bonus.c\
	   set_texture_2_bonus.c\
	   set_texture_3_bonus.c\
	   set_texture_4_bonus.c\
	   set_texture_5_bonus.c\
	   set_texture_6_bonus.c\
	   set_texture_7_bonus.c\
	   set_texture_8_bonus.c\
	   set_texture_9_bonus.c\
	   set_texture_10_bonus.c\
	   set_texture_11_bonus.c\
	   set_texture_12_bonus.c\
	   set_color_bonus.c\
	   set_map_bonus.c\
	   set_map_2_bonus.c\
	   set_map_3_bonus.c\
	   set_door_map_bonus.c\
	   set_timer_map_bonus.c\
	   check_map_bonus.c\
	   check_map_2_bonus.c\
	   clean_map_bonus.c\
	   check_pattern_config_bonus.c\
	   check_file_bonus.c\
	   set_config_bonus.c\
	   set_const_bonus.c\
	   set_const_2_bonus.c\
	   set_player_bonus.c\
	   set_bonus_bonus.c\
	   set_enemies_bonus.c\
	   set_screens_bonus.c\
	   set_game_bonus.c\
	   initialize_clean_check_bonus.c\
	   initialize_bonus_check_bonus.c\
	   initialize_game_bonus.c\
	   move_bonus.c\
	   collision_bonus.c\
	   camera_bonus.c\
	   crouch_bonus.c\
	   jump_bonus.c\
	   cell_bonus.c\
	   check_cell_bonus.c\
	   check_cell_2_bonus.c\
	   get_next_cell_bonus.c\
	   look_around_bonus.c\
	   hit_bonus.c\
	   horizontal_hit_bonus.c\
	   vertical_hit_bonus.c\
	   sprite_hit_bonus.c\
	   sprite_list_bonus.c\
	   life_bar_bonus.c\
	   reward_count_bonus.c\
	   screen_bonus.c\
	   upper_screens_bonus.c\
	   pick_and_kick_bonus.c\
	   ray_casting_bonus.c\
	   print_bonus.c\
	   set_pixel_color_bonus.c\
	   set_pixel_color_2_bonus.c\
	   set_pixel_color_3_bonus.c\
	   distance_bonus.c\
	   screenshot_bonus.c\
	   enemy_texture_bonus.c\
	   enemy_texture_2_bonus.c\
	   enemy_hit_bonus.c\
	   enemy_event_bonus.c\
	   enemy_behavior_bonus.c\
	   enemy_behavior_2_bonus.c\
	   door_event_bonus.c\
	   door_event_2_bonus.c\
	   weapon_event_bonus.c\
	   health_event_bonus.c\
	   exit_bonus.c\
	   clean_bonus.c\
	   clean_2_bonus.c\
	   next_level_bonus.c\
	   game_over_bonus.c\
	   victory_bonus.c\
	   manage_thread_bonus.c\
	   push_screens_bonus.c

ifdef WITH_BONUS
	SRCS_NAME = ${SRCS_NAME_BONUS}
	LDFLAGS = ${LDFLAGS_BONUS}
	CFLAGS = ${CFLAGS_BONUS}
else
	SRCS_NAME = ${SRCS_NAME_DFLT}
	LDFLAGS = ${LDFLAGS_DFLT}
	CFLAGS = ${CFLAGS_DFLT}
endif

INC_DFLT = ${addprefix ${INC_DIR}, ${INC_NAME_DFLT}}
INC_BONUS = ${addprefix ${INC_DIR}, ${INC_NAME_BONUS}}
OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAME:.c=.o}}

MLX = ${MLX_DIR}libmlx_Linux.a
LIBFT = ${LIBFT_DIR}libft.a
NAME = cub3D

all: ${NAME}

${NAME}: ${OBJS_DIR} ${MLX} ${LIBFT} ${OBJS}
	@${CC} -o $@ ${OBJS} ${CFLAGS} ${LDFLAGS}
	@echo "${NAME} done."

bonus:
	@make WITH_BONUS=1 all

${OBJS_DIR}:
	@mkdir ${OBJS_DIR}

${LIBFT}:
	@${MAKE} -C libft

${MLX}:
	@${MAKE} -C minilibx

${OBJS_DIR}set_config.o: ${INC_DIR}gl_file_parsing.h

${OBJS_DIR}exit.o: ${INC_DIR}gl_error_message.h

${OBJS_DIR}event.o: ${INC_DIR}gl_key_param.h

${OBJS_DIR}set_config_bonus.o: ${INC_DIR}gl_file_parsing_bonus.h

${OBJS_DIR}exit_bonus.o: ${INC_DIR}gl_error_message_bonus.h

${OBJS_DIR}event_bonus.o: ${INC_DIR}gl_key_param_bonus.h

${OBJS_DIR}enemy_event_bonus.o: ${INC_DIR}gl_enemy_behavior_bonus.h

${OBJS_DIR}enemy_hit_bonus.o: ${INC_DIR}gl_enemy_texture_bonus.h

${OBJS_DIR}%_bonus.o: ${SRCS_DIR}%_bonus.c ${INC_BONUS}
	@${CC} -o $@ -c $< ${CFLAGS_BONUS}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${INC_DFLT}
	@${CC} -o $@ -c $< ${CFLAGS_DFLT}

clean:
	@${MAKE} -C libft clean
	@${MAKE} -C minilibx clean
	@rm -rf ${OBJS_DIR}
	@echo "clean done."

fclean: clean
	@rm -f ${NAME} ${MLX} ${LIBFT}
	@echo "fclean done."

re: fclean all

.PHONY: all clean fclean re bonus
