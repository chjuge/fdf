DIR		= 	src

SRCS	=	$(DIR)/create_new_remainder.c \
			$(DIR)/cut_from_remainder.c \
			$(DIR)/find_end_of_line.c \
			$(DIR)/find_len_next_line.c \
			$(DIR)/get_next_line.c \
			$(DIR)/read_file_gnl.c \
			$(DIR)/utils.c \
			$(DIR)/fdf.c \
			$(DIR)/fill_list.c \
			$(DIR)/ft_atoi.c \
			$(DIR)/ft_strncmp.c \
			$(DIR)/ft_split.c

OBJS	= 	$(SRCS:.c=.o)

HEAD	=	header/fdf.h

MINLIB	=	minilibx_macos/libmlx.a
# MINLIB	=	minilibx-linux/libmlx.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 

RM		=	rm -rf

NAME	=	fdf

all:		$(NAME)

%.o:		%.c	$(HEAD) 
# $(CC) $(CFLAGS) -O3 -c $< -o $@
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS) $(HEAD) 
			$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# $(CC) $(CFLAGS) $(OBJS) $(MINLIB) -lXext -lX11 -lm -lz -o $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 
