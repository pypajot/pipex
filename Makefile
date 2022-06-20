SRCS_ := main.c
SRCS := $(patsubst %,srcs/%,$(SRCS_))

OBJ := $(patsubst %.c,%.o,$(SRCS))

NAME := pipex

INC := pipex.h

LIBFT := libft/libft.a

CC := gcc
FLAGS := -Wall -Wextra -Werror

all : $(NAME)


%.o : %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@


$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)


clean:
	rm -f $(OBJ)
	make -C $(dir $(LIBFT)) clean


fclean:
	rm -f $(OBJ) $(NAME)
	make -C $(dir $(LIBFT)) fclean


$(LIBFT):
	make -C $(dir $(LIBFT))


re:
	make fclean
	make all