NAME= bureaucrat

CC		= c++
CF		= -Wall -Wextra -Werror -std=c++98

OBJ_DIR	= .obj

HEADER	= Bureaucrat.hpp
SRC		= Bureaucrat.cpp main.cpp
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

GREEN	= \033[32m
RED		= \033[0;31m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CF) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation complete. Executable '$(NAME)' created.$(RESET)"

$(OBJ_DIR)/%.o: %.cpp  $(HEADER) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CF) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable '$(NAME)' removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re