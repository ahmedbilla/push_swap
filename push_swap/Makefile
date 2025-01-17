# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 11:15:59 by ahbilla           #+#    #+#              #
#    Updated: 2025/01/15 21:08:13 by ahbilla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c includes/ft_atoi.c includes/is_numeric.c\
	includes/has_duplicate.c includes/process_arguments.c\
	includes/ft_split.c includes/put_in_a.c src/swap.c\
	src/algo_two.c src/algo_three.c src/rotate.c src/reverse.c\
	src/push.c includes/search_min_number.c src/algo_four.c includes/is_sorted.c\
	src/algo_five.c includes/list_size.c src/index_stack_elements.c src/sort_utils.c\
	src/algo_more_than_five.c includes/search_max_number.c


	
	
	

OBJS = ${SRCS:.c=.o}
NAME = push_swap
LIBC = ar -rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o:%.c push_swap.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} $(OBJS) -o push_swap



clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : clean