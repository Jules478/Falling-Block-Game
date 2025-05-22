NAME = tetris

CC = cc

LINK = -lncurses

RM = rm -rf

SRC_DIR = srcs
SRCS = \
			$(SRC_DIR)/init.c \
			$(SRC_DIR)/tetris.c \
			$(SRC_DIR)/draw_ui.c \
			$(SRC_DIR)/generate_tetromino.c \
			$(SRC_DIR)/draw_game_state.c \
			$(SRC_DIR)/run_game.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/rotation.c \
			$(SRC_DIR)/speed.c

OBJ_DIR = ./obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR 		= ./libft

LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = -I./include -I$(LIBFT_DIR)/include

INCLUDE_DIR := include

HEADERS_DEP = include/tetris.h

LIB_FILES := raylib.a
LIB_INCLUDE_DIR := raylib/src

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIB_INCLUDE_DIR) -g #-fsanitize=address 
LIBRARY_FLAGS := -lm -ldl -lpthread -lGL -lrt -lX11

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \033[0m

all: $(LIBFT) $(NAME)

$(NAME): $(LIB_FILES) $(OBJS)
	@$(CC) $(OBJS) $(LIB_FILES) $(CFLAGS) $(LIBFT) $(HEADERS) $(LIBRARY_FLAGS) $(LINK) -o $(NAME)
	@echo "$(GREEN) \nGame Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_DEP)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(GREEN)\nOBJS Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(GREEN)\nExecutable Clean Complete\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

full: fclean all
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(GREEN)\nOBJS Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

.PHONY: all clean fclean re full