DIR		= 	src

SRCS	=	$(DIR)/gnl_utils.c \
			$(DIR)/get_next_line.c \
			$(DIR)/utils1.c \
			$(DIR)/utils2.c \
			$(DIR)/fdf.c \
			$(DIR)/fill_map.c \
			$(DIR)/ft_atoi.c \
			$(DIR)/ft_strncmp.c \
			$(DIR)/ft_split.c \
			$(DIR)/ft_substr.c \
			$(DIR)/ft_strtrim.c \
			$(DIR)/ft_strlcpy.c \
			$(DIR)/draw_line.c \
			$(DIR)/lstnew.c \
			$(DIR)/add_back.c \
			$(DIR)/find_smth_of_line.c \
			$(DIR)/free.c \
			$(DIR)/drawmap.c \
			$(DIR)/matrix.c \
			$(DIR)/key_listener.c \
			$(DIR)/change.c \
			$(DIR)/get_matrix.c \
			$(DIR)/rotate_xyz.c \
			$(DIR)/point_vector.c \
			$(DIR)/initialization.c \
			$(DIR)/state_matrix.c \
			$(DIR)/instance.c \
			$(DIR)/my_mlx_pixel_put.c 

OBJS	= 	$(SRCS:.c=.o)

HEAD	=	header/fdf.h

# MINLIB	=	minilibx_macos/libmlx.a
# MINLIB	=	minilibx-linux/libmlx.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 

RM		=	rm -rf

NAME	=	fdf

all:		$(NAME)

%.o:		%.c	$(HEAD) 
			$(CC) $(CFLAGS) -Imlx -c $< -o $@
# $(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME):	$(OBJS) $(HEAD) 
			$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# $(CC) $(CFLAGS) $(OBJS) $(MINLIB) -lXext -lX11 -lm -lz -o $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 
