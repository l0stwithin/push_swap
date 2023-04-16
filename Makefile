# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 23:53:30 by akaraban          #+#    #+#              #
#    Updated: 2023/04/16 06:02:27 by akaraban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

SOURCES =	algorithm.c \
			algorithm2.c \
			algorithm3.c \
			algorithm4.c \
			algorithm5.c \
			combined_opns.c \
			error_check.c \
			indices.c \
			input_processing.c \
			main.c \
			push_swap_opns.c \
			rotate_opns.c \
			stack_utilities.c \
			stack_utilities2.c \
			utilities.c \
			utilities2.c
			
OBJECTS = ${SOURCES:.c=.o}

CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RESET = \033[0m

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
		
$(NAME): $(OBJECTS) 
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)Success: $(RESET) Compilation ended successfully"

all: $(NAME) 
	
clean :
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)
	@echo "$(GREEN)Success: $(RESET) Objects are removed"

re : fclean all

.PHONY: all clean fclean re
