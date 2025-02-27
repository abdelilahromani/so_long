NAME = so_long
NAME_BONUS = so_long_bonus

CFLAGS = -Wall -Wextra -Werror -Imlx -fsanitize=address -g

CC = cc

SRCF = 	ft_printf/ft_printf.c \
		ft_printf/ft_printhexa.c \
		ft_printf/ft_putchar.c \
		ft_printf/ft_putnbr.c \
		ft_printf/ft_putnbrbase.c \
		ft_printf/ft_putnbrunsig.c \
		ft_printf/ft_putstr.c \
		get_next_linev2/get_next_line.c \
	  	get_next_linev2/get_next_line_utils.c \
	  	parcing/parc_utils1.c \
	  	parcing/parc_utils2.c \
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

BSRCF = bonus/ft_printf/ft_printf.c \
		bonus/ft_printf/ft_printhexa.c \
		bonus/ft_printf/ft_putchar.c \
		bonus/ft_printf/ft_putnbr.c \
		bonus/ft_printf/ft_putnbrbase.c \
		bonus/ft_printf/ft_putnbrunsig.c \
		bonus/ft_printf/ft_putstr.c \
		bonus/get_next_linev2/get_next_line.c \
	  	bonus/get_next_linev2/get_next_line_utils.c \
	  	bonus/parcing/parc_utils1.c \
	  	bonus/parcing/parc_utils2.c \
	  	bonus/parcing/floodfill.c \
	  	bonus/src/ft_strcmp.c \
	  	bonus/src/ft_strdup.c \
	  	bonus/src/ft_strjoin.c \
	  	bonus/src/ft_split.c \
	  	bonus/src/helpe_fc.c \
	  	bonus/src/lstclear.c \
	  	bonus/src/ft_atoi.c \
	  	bonus/src/ft_itoa.c \
	  	bonus/drawing/drawing.c \
	  	bonus/drawing/moves_keys.c \
	  	bonus/so_long.c

OBJF = $(SRCF:.c=.o)
BOBJF = $(BSRCF:.c=.o)

HF = includes/so_long.h includes/get_next_line.h includes/ft_printf.h
BHF = bonus/includes/so_long.h bonus/includes/get_next_line.h bonus/includes/ft_printf.h
all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(BOBJF)
	$(CC) $(CFLAGS) $(BOBJF) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

$(NAME):$(OBJF)
	$(CC) $(CFLAGS) $(OBJF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus/%.o : bonus/%.c $(BHF)
	$(CC) $(CFLAGS) -c $< -o $@
%.o : %.c $(HF)
	$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJF)
 