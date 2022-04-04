DIR		= 	src

SRCS	=	$(DIR)/create_new_remainder.c \
			$(DIR)/cut_from_remainder.c \
			$(DIR)/find_end_of_line.c \
			$(DIR)/find_len_next_line.c \
			$(DIR)/get_next_line.c \
			$(DIR)/read_file_gnl.c \
			$(DIR)/utils.c \
			$(DIR)/fdf.c

OBJS	= 	$(SRCS:.c=.o)

HEAD	=	header/fdf.h

MINLIB	=	minilibx-linux/libmlx.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 

RM		=	rm -rf

NAME	=	fdf

all:		$(NAME)

%.o:		%.c	$(HEAD) 
			$(CC) $(CFLAGS) $(MINLIB) -O3 -c $< -o $@

$(NAME):	$(OBJS) $(HEAD) 
			$(CC) $(CFLAGS) $(OBJS) $(MINLIB) -lXext -lX11 -lm -lz -o $(NAME)

clean:		
			$(RM) $(OBJS) $(OM) $(BOBJS)

fclean:		clean
			$(RM) $(NAME) $(BNAME)

re:			fclean all

.PHONY:		all clean fclean re 
