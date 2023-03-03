# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 17:52:25 by fmoreira          #+#    #+#              #
#    Updated: 2023/03/01 19:15:11 by fmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -g
FLAGS	= -pthread

INCD_	= philo.h
INCD_DIR	= ./include

SRCS	= main.c ft_verify.c ft_time.c ft_init_table.c ft_routine.c\
			ft_utils0.c ft_utils1.c ft_utils2.c ft_free.c
SRCS_DIR	= ./srcs

OBJS_DIR	= ./objs
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

SRCS_PATH	= $(addprefix $(SRCS_DIR)/, $(SRCS))

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCD_DIR) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(FLAGS) -I $(INCD_DIR) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) debug

re: fclean all

debug: $(OBJS)
	$(CC) -g $(CFLAGS) $(FLAGS) -I $(INCD_DIR) $(SRCS_PATH) -o $@

.PHONY: all clean fclean re