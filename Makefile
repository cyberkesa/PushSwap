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
			alg.c \
			back_push.c \
			super_ins_push_rotate.c \
			new_super_alg.c \
			mark_up.c

SRCD =		src/

OBJECTS =	$(addprefix $(OBJD), $(patsubst %.c, %.o, $(SRS)))

INCLUDES =	-I inc/ -I Libft/

CFLAGS =	-O2 -fsanitize=address -g

CC =		gcc

all: $(NAME)

$(NAME):: $(LIBFT) $(OBJD)
$(NAME):: $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(INCLUDES) $^ $(LIBFT)
	@printf "\x1b[7m Create: "
	@printf $@
	@printf "\x1b[7m\n"

$(LIBFT):
	@make -C ./Libft

$(OBJD)%.o: $(SRCD)%.c
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
