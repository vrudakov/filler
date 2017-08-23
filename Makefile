NAME = vrudakov.filler

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/
INC_PATH = ./includes/ ./libft/includes/
OBJ_NAME =  $(SRC_NAME:.c=.o)
SRC_NAME = int_map.c piece_serv.c reading.c main.c 
LIBFT = libft.a
LIB_NAME = -lft

FLAG = -Wall -Wextra -Werror
CC = gcc -Ofast

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)
	cp $(NAME) players

$(NAME): $(OBJ)
	$(CC) $(LIB) $(LIB_NAME) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(FLAG) $(INC) -o $@ -c $<

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C ./libft/

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	@make -C ./libft/ fclean

re: fclean all

.PHONY: lib clean fclean re
