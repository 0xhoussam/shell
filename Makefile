CC=gcc
NAME=minishell
BIN_DIR=./bin/
INCLUDE=-I include -I lib/libft
CFLAGS=-Wall -Werror -Wextra $(INCLUDE)
LIBFT_DIR=./lib/libft/
LIBFT=libft.a
SRC_DIR=./src/
SRC_FILES=main.c
CFILES=$(addprefix $(SRC_DIR), $(SRC_FILES))
OFILES=$(patsubst %.c, %.o, $(CFILES))

all: $(NAME)

$(NAME): $(OFILES) build

build:
	mkdir -p $(BIN_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(LIBFT_DIR)$(LIBFT) $(OFILES) -o $(BIN_DIR)$(NAME)

fsanitize: CFLAGS += -fsanitize=address
fsanitize: all
	mkdir -p $(BIN_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(OFILES) $(LIBFT_DIR)$(LIBFT) -fsanitize=address -o $(BIN_DIR)$(NAME)

re: all fclean
	$(MAKE) -C $(LIBFT_DIR) re

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(BIN_DIR)$(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OFILES)
