NAME	=	Cub3D

DIR		=	srcs/

SRCS	=	$(DIR)main.c	\
			$(DIR)get_next_line.c	\
			$(DIR)get_next_line_utils.c	\
			$(DIR)fct_display.c	\
			$(DIR)manage_keys.c	\
			$(DIR)ft_split.c	\
			$(DIR)ft_atoi.c	\
			$(DIR)manage_move.c	\
			$(DIR)fct_init.c	\
			$(DIR)manage_wall.c	\
			$(DIR)manage_sprite.c	\
			$(DIR)fct_tools.c	\
			$(DIR)manage_floor.c	\
			$(DIR)fct_parsing.c	\
			$(DIR)fct_check_map.c	\
			$(DIR)manage_text.c	\
			$(DIR)ft_screenshot.c	\

DIRH	=	includes/

OBJS	=	$(SRCS:%.c=%.o)

MLX_PRE	= 	 -lmlx -framework OpenGL -framework AppKit

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I./$(DIRH)

$(NAME):	$(OBJS) $(DIRH)
			$(CC) $(OBJS) $(MLX_PRE) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		re all clean fclean