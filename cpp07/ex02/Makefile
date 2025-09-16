NAME= array

CC		= c++
CF		= -Wall -Wextra -Werror -std=c++98 -MMD -MP

OBJ_DIR	= .obj
DEP_DIR = .dep

HEADER	= Array.hpp
SRC		= main.cpp
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEP		=$(addprefix $(DEP_DIR)/, $(OBJ:.o=.d))

GREEN	= \033[32m
RED		= \033[0;31m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CF) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation complete. Executable '$(NAME)' created.$(RESET)"

$(OBJ_DIR)/%.o: %.cpp  $(HEADER) Makefile
	@mkdir -p $(dir $@)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CF) -c $< -o $@ -MF $(DEP_DIR)/$*.d

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(DEP_DIR)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable '$(NAME)' removed.$(RESET)"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re