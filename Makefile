DIR		= 	src

MAIN	=	$(DIR)/main.c

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

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra 

RM		=	rm -rf

NAME	=	fdf

all:		$(NAME)

%.o:		%.c	$(HEAD)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEAD)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:		
			$(RM) $(OBJS) $(OM) $(BOBJS)

fclean:		clean
			$(RM) $(NAME) $(BNAME)

re:			fclean all

.PHONY:		all clean fclean re 
