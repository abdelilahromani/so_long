NAME = so_long

CFLAGS = -Wall -Wextra -Werror -Imlx -fsanitize=address -g

CC = cc

SRCF = get_next_linev2/get_next_line.c \
	  get_next_linev2/get_next_line_utils.c \
	  parcing/parc_utils1.c \
	  parcing/floodfill.c \
	  src/ft_strcmp.c \
	  src/ft_strdup.c \
	  src/ft_strjoin.c \
	  src/ft_split.c \
	  src/helpe_fc.c \
	  src/lstclear.c \
	  src/ft_atoi.c \
	  src/ft_itoa.c \
	  drawing/drawing.c \
	  drawing/moves_keys.c \
	  so_long.c

OBJF = $(SRCF:.c=.o)

HF = includes/so_long.h includes/get_next_line.h

all : $(NAME)

$(NAME):$(OBJF)
	$(CC) $(CFLAGS) $(OBJF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJF)
 