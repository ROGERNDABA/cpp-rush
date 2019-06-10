# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 15:55:44 by Roger Ndaba       #+#    #+#              #
#    Updated: 2019/06/10 16:53:19 by Roger Ndaba      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC = clang++ -Wall -Wextra -Werror -lncurses

SRC = Bullet.cpp  Enemy.cpp  main.cpp  Screen.cpp  SpaceShip.cpp  Window.cpp


all: $(NAME)
$(NAME):
	@$(CC) $(SRC) -o $(NAME) 
	@printf "\e[1;32mCompiled successfully\e[0m\n"

fclean:
	@rm -rf $(NAME)

re: fclean all

