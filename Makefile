# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 13:40:03 by mbelorge          #+#    #+#              #
#    Updated: 2020/02/10 14:36:21 by mbelorge         ###   ########.fr        #
#                                                                              #
# *****************************************************************************#

NAME = so_long

SRCS	=	so_long.c\
			playing/keyboard_control.c\
			parsing/check_map.c\
			playing/sprite_init.c\
			playing/game.c\
			parsing/check_error.c\
			parsing/error.c\
			playing/initialisation.c\
			parsing/free.c\
			playing/moove.c\
			playing/draw.c\
			parsing/tools.c\
			playing/fill_sprit_data.c\

SRCS_BONUS	=	bonus/so_long_bonus.c\
			bonus/keyboard_control_bonus.c\
			bonus/check_map_bonus.c\
			bonus/sprite_init_bonus.c\
			bonus/game_bonus.c\
			bonus/check_error_bonus.c\
			bonus/error_bonus.c\
			bonus/initialisation_bonus.c\
			bonus/free_bonus.c\
			bonus/moove_bonus.c\
			bonus/draw_bonus.c\
			bonus/tools_bonus.c\
			bonus/fill_sprit_data_bonus.c\

CC		= gcc
CFLAGS	= -Wextra -Werror -Wall -g
RM		= rm -f
LIB_D	= ./libft
MLX_D	= ./minilibx
HEADER	= -I /so_long.h
HEADER_BONUS	= -I /solong_bonus.h
OBJS	= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

.c.o:
			${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C ${LIB_D}
			${CC} ${HEADER} ${OBJS} -o ${NAME} -O -O3 -L ${LIB_D} -lft -L ${MLX_D} -lmlx -lXext -lX11 -lm

all:		${NAME}

clean:
			make clean -C ${LIB_D}
			${RM} ${OBJS}
			${RM} ${OBJS_BONUS}

fclean:		clean
			make fclean -C ${LIB_D}
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJS_BONUS}
			make -C ${LIB_D}
			${CC} ${HEADER_BONUS} ${OBJS_BONUS} -o ${NAME} -O -O3 -L ${LIB_D} -lft -L ${MLX_D} -lmlx -lXext -lX11 -lm



.PHONY:		all clean fclean re run