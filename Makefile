NAME = vrudakov.filler
LIBFT = libft.a
SRC_PATH = src
OBJ_PATH = obj
SRC_NAME = second.c main.c 
FLAG = -Wall -Wextra -Werror


# OBJ = $(subst .c, .o, $(SRC))
OBJ = $(addprefix $(OBJ_PATH)/, $$(SRC_NAME:.c=.o))
LIBX = -L ./libft/ -lft -I/usr/local/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(LIBX) $(OBJ) -o $(NAME) 

$(LIBFT):
	@make -C ./libft/
	
$(addprefix $(OBJ_PATH)/, %.o): $(addprefix $(SRC_PATH)/, %.c)
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAG) -o $@ -c $^

compile:
	gcc $(FLAG) -o $(NAME) $(SRC) ft_printf/libftprintf.a


clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:	fclean all
 
.PHONY: all clean fclean re