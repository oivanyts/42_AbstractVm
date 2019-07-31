NAME 		    = abstractVm

SRC             += main.cpp

SRC_DIR         = ./src/
INC_DIR         = ./inc/
OBJ_DIR         = ./obj/

CC              := clang++

HEADER_FLAGS    := -I $(INC_DIR)

FLAGS		    := -Wall -Wextra -Werror -std=c++14 $(HEADER_FLAGS)

OBJ 		    := $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo compiling $@;
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)
	@echo "\033[01;48;05;22m DONE \033[m [$(NAME)]"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo compiling $@;
	$(CC) -c $< -o $@ $(FLAGS);

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[01;48;05;160m fclean succsed \033[m [$(NAME)]"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
