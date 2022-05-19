CC=gcc
NAME=minishell
BIN_DIR=./bin/
INCLUDE=-I include
CFLAGS=-Wall -Werror -Wextra $(INCLUDE)
SRC_DIR=./src/
SRC_FILES=main.c
CFILES=$(addprefix $(SRC_DIR), $(SRC_FILES))
OFILES=$(patsubst %.c, %.o, $(CFILES))

all: $(NAME)

$(NAME): $(OFILES) build

build:
	mkdir -p $(BIN_DIR)
	$(CC) $(OFILES) -o $(BIN_DIR)$(NAME)

fsanitize: CFLAGS += -fsanitize=address
fsanitize: all
	mkdir -p $(BIN_DIR)
	$(CC) $(OFILES) -fsanitize=address -o $(BIN_DIR)$(NAME)

re: all fclean

fclean: clean
	rm -f $(BIN_DIR)$(NAME)

clean:
	rm -f $(OFILES)
