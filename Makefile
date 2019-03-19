NAME = program.bin

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

SRC_DIR = ./src/
OBJ_DIR = ./obj/

#===========================================================
SRC_LIST =	main.c \
			input.c sort.c
#===========================================================



OBJ_LIST = $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_LIST)
	$(CC) $(OBJ_LIST) -o $(NAME)
	@echo "==================================================================="

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $^ -o $@


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

zip: $(NAME)
	zip src.zip Makefile head.h $(SRC_LIST)
#	./$(NAME) input_files/file_1 > 1.out
#	./$(NAME) input_files/file_2 > 2.out
#	./$(NAME) input_files/file_3 > 3.out
#	./$(NAME) input_files/file_4 > 4.out

.PHONY = all clean fclean re zip
