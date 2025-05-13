NAME = tetris

CC = cc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LINK = -lncurses

RM = rm -rf

SRCS = \
			srcs/init.c \
			srcs/tetris.c

OBJS = $(SRCS:.c=.o)

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)
	@echo "$(GREEN) \nGame Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

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