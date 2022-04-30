# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 08:41:10 by aoteo-be          #+#    #+#              #
#    Updated: 2022/01/20 12:03:04 by aoteo-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compilation flags
CC          = gcc
CFLAGS	    = -Wall -Wextra -Werror -pthread

# Directories
INC_DIR		= ./include

# Executable
NAME		= philo

# Sources
SRCS    	= actions.c ft_atoi.c ft_split.c ft_strjoin.c\
		memory_management.c parsing.c philo.c philo_utils.c
#Object files
OBJS        = $(SRCS:.c=.o)

all :       $(NAME)

$(NAME):    $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -IINC_DIR -o $(NAME)

clean :
		    rm -f $(OBJS)

fclean :    clean
		    rm -f $(NAME)

re :        fclean all

.PHONY :    all clean fclean make re
