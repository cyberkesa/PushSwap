NAME =		push_swap

LIBFT =		Libft/libft.a

OBJD =		objects/

SRS =		main.c \
			make_array.c \
			quick_sort.c \
			prints.c \
			algorithm.c \
			check_error.c \
			ins_push_pa.c \
			ins_push_pb.c \
			ins_swap.c \
			ins_rotate.c \
			ins_adjacent.c \
			ins_adjacent_1.c \
			get_utils.c \
			check_sorts.c \
			alg_five.c \
			super_ins_push_rotate.c \
			lis.c \
			lis_stack_a.c \
			stack_b_back.c \
			stack_b_init.c \
			stack_b_back_1.c \
			stack_b_back_alg.c \
			stack_b_utils.c \
			stack_a_push.c \
			errors.c

SRCD =		src/

OBJECTS =	$(addprefix $(OBJD), $(patsubst %.c, %.o, $(SRS)))

INCLUDES =	-I inc/ -I Libft/

CFLAGS =	-O2 -fsanitize=address -g

CC =		gcc

all: lib $(NAME)

$(NAME):: $(LIBFT) $(OBJD)
$(NAME):: $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(INCLUDES) $^
	@printf "\x1b[7mCreate: "
	@printf $@
	@printf "\x1b[7m\n"

$(LIBFT): lib

lib:
	@make -C ./Libft

$(OBJD)%.o: $(SRCD)%.c	inc/push_swap.h Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "\x1b[2m\x1b[m Compile object: "
	@printf $(notdir $@)
	@printf "\x0b\n"

$(OBJD):
	@mkdir -p $@

clean:
	@make clean -C ./Libft
	@rm -rf $(OBJD)

fclean: clean
	@make fclean -C ./Libft
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
