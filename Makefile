NAME = fdf

BONUS_PROGRAM = fdf_bonus

MANDATORY = srcs/main.c

BONUS = bonus/bonus.c

SRCS =	srcs/main_utils.c 			\
		srcs/main_utils_two.c 		\
		srcs/read_fdf.c 			\
		srcs/draw_map.c 			\
		srcs/matrex_funcs.c 		\
		srcs/matrex_actions.c 		\
		gnl/get_next_line.c 		\
		gnl/get_next_line_utils.c 	\
		tools/ft_strncmp.c 			\
		tools/ft_atoi.c 			\
		tools/ft_split.c 			\
		tools/ft_strlcpy.c 			\
		tools/ft_strnstr.c 			\
		tools/ft_strlen.c 			\
		matrex/matrex.c 			\

OBJS = ${SRCS:.c=.o}

OBJSMAN = ${MANDATORY:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

%.o: %.c
	$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : ${NAME}

${NAME}: ${OBJS} ${OBJSMAN}
			${CC} ${OBJS} ${OBJSMAN} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

bonus : ${BONUS_PROGRAM}

${BONUS_PROGRAM}: ${OBJS} ${OBJSBONUS}
					${CC} ${OBJS} ${OBJSBONUS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${BONUS_PROGRAM}


clean:
		${RM} ${OBJS} ${OBJSBONUS} ${OBJSMAN}

fclean:		clean
			${RM} ${NAME} ${BONUS_PROGRAM}

re:			fclean all

.PHONY:		clean fclean all re