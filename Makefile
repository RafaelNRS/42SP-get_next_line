# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 07:19:21 by ranascim          #+#    #+#              #
#    Updated: 2022/05/23 07:52:18 by ranascim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

LIB = get_next_line.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c \
                get_next_line_utils.c

OBJ = $(SRC:.c=.o)

#BONUS = ft_lstnew.c \
#                ft_lstadd_front.c \
#                ft_lstsize.c \
#                ft_lstlast.c \
#                ft_lstadd_back.c \
#                ft_lstdelone.c \
#                ft_lstclear.c \
#                ft_lstiter.c \
#                ft_lstmap.c

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(LIB)
		$(CC) $(CFLAGS) -c $(SRC) -I .
		ar -rc $(NAME) $(OBJ)

#bonus: $(BONUS) $(LIB)
#		$(CC) $(CFLAGS) -c $(BONUS) -I .
#		ar -rc $(NAME) $(OBJ_BONUS)

#clean:
#	rm -f $(OBJ) $(OBJ_BONUS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
