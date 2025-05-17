NAME = tetris

CC = cc


LINK = -lncurses

RM = rm -rf

SRCS = \
			srcs/init.c \
			srcs/tetris.c \
			srcs/draw_ui.c \
			srcs/generate_tetromino.c \
			srcs/draw_game_state.c \
			srcs/run_game.c \
			srcs/utils.c \
			srcs/rotation.c

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR := include

LIB_FILES := raylib.a
LIB_INCLUDE_DIR := raylib/src

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIB_INCLUDE_DIR) -g #-fsanitize=address 
LIBRARY_FLAGS := -lm -ldl -lpthread -lGL -lrt -lX11

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIB_FILES) $(OBJS)
	@$(CC) $(OBJS) $(LIB_FILES) $(CFLAGS) $(LIBRARY_FLAGS) $(LINK) -o $(NAME)
	@echo "$(GREEN) \nGame Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@echo "$(GREEN)\nOBJS Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)\nExecutable Clean Complete\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

full: fclean all
	@$(RM) $(OBJS)
	@echo "$(GREEN)\nOBJS Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

.PHONY: all clean fclean re full