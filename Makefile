NAME := pipex

NAME_BONUS := pipex_bonus

CC := gcc
FLAGS := -Wall -Wextra -Werror

SRCDIR := srcs
OBJDIR := objs

SRCS_ := close_all_fd.c  free_data.c  exec_cmd.c  init_data.c  main.c \
run_all_cmd.c ft_error.c
SRCS := $(patsubst %,$(SRCDIR)/%,$(SRCS_))

SRCS_BONUS_ := close_all_fd.c  free_data.c  exec_cmd.c  init_data.c  main_bonus.c \
run_all_cmd.c ft_error.c
SRCS_BONUS := $(patsubst %,$(SRCDIR)/%,$(SRCS_))

OBJ := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS_))

OBJ_BONUS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS_BONUS_))

INC := pipex.h

LIBFT := libft/libft.a



all : $(NAME)


$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INC)
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@


$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)


clean:
	rm -fd $(OBJ) $(OBJ_BONUS) $(OBJDIR)
	make -C $(dir $(LIBFT)) clean


fclean:
	rm -fd $(OBJ) $(OBJ_BONUS) $(NAME) $(NAME_BONUS) $(OBJDIR)
	make -C $(dir $(LIBFT)) fclean


$(LIBFT):
	make -C $(dir $(LIBFT))


re:
	make fclean
	make all


bonus : $(NAME_BONUS)


$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBFT)


.PHONY: clean fclean re all bonus
