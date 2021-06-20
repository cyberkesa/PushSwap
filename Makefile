# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:04:48 by vwinfred          #+#    #+#              #
#    Updated: 2021/01/14 19:17:23 by vwinfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

LIBFT =		Libft/libft.a

OBJD =		objects/

SRS =		main.c \
			make_array.c \
			quick_sort.c \
			prints.c \
			algorithm.c \
			check_error.c \
			ins_push.c \
			ins_swap.c \
			ins_rotate.c \
			ins_adjacent.c \
			get_utils.c \
			check_sorts.c \
			complete.c \
			algorithm_before.c \
			utils_alg.c \
			back_push.c \
			super_ins_push_rotate.c \
			lis.c \
			lis_stack_a.c \
			my_best.c \
			stack_b_back.c

SRCD =		src/

OBJECTS =	$(addprefix $(OBJD), $(patsubst %.c, %.o, $(SRS)))

INCLUDES =	-I inc/ -I Libft/

CFLAGS =	-O2 -fsanitize=address -g

CC =		gcc

all: lib $(NAME)

$(NAME):: $(LIBFT) $(OBJD)
$(NAME):: $(OBJECTS) $(LIBFT) #CHECKER
	@$(CC) $(CFLAGS) -o $@ $(INCLUDES) $^
#CHECKER
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
