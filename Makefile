SRCDIR := srcs
OBJDIR := objs

SRCS_ := close_all_fd.c  free_data.c  get_path.c  init_data.c  main.c \
run_all_cmd.c ft_error.c
SRCS := $(patsubst %,$(SRCDIR)/%,$(SRCS_))

OBJ := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS_))

NAME := pipex

INC := pipex.h

LIBFT := libft/libft.a

CC := gcc
FLAGS := -Wall -Wextra -Werror

all : $(NAME)


$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INC)
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@


$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)


clean:
	rm -fd $(OBJ) $(OBJDIR)
	make -C $(dir $(LIBFT)) clean


fclean:
	rm -fd $(OBJ) $(NAME) $(OBJDIR)
	make -C $(dir $(LIBFT)) fclean


$(LIBFT):
	make -C $(dir $(LIBFT))


re:
	make fclean
	make all

bonus: all


.PHONY: clean fclean re all bonus
