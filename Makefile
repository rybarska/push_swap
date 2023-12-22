LIBFT_DIR = libft
INCLUDE_DIR = include

HEADER_SRC = $(INCLUDE_DIR)/push_swap.h
SRC = ./main.c \
	./set_num.c \
	./clean.c \
	./swaps.c \
	./pushes.c \
	./rotations.c \
	./rev_rotations.c \
	./sort_small.c \
	./sort_big_radix.c \
	./set_stacks.c \
	./utils.c \

OBJ = $(SRC:%.c=%.o)

CC = cc
CPPFLAGS = -Werror -Wextra -Wall -I ./include -I $(LIBFT_DIR)
LDFLAGS = -L$(LIBFT_DIR)

NAME = push_swap

all:$(NAME)

$(NAME):$(OBJ) $(LIBFT_DIR)/libft.a
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)
	
$(OBJ): $(HEADER_SRC) $(LIBFT_DIR)/libft.h

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) libft.a
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
