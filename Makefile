# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 17:06:02 by fbouibao          #+#    #+#              #
#    Updated: 2021/06/30 21:12:38 by fbouibao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS =

SRC = philo.c treads.c philo_tools.c print.c main_cnt.c\

SRC_B =  

CC = gcc

all: $(NAME)

NAME_B = checker

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B):
	$(CC) $(FLAGS) $(SRC_B) -o $(NAME_B)

clean:
	@echo "no .o available"

fclean: clean 
	@rm -rf $(NAME) $(NAME_B)
	
re: fclean all