# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 00:49:22 by madumerg          #+#    #+#              #
#    Updated: 2024/08/05 11:06:20 by madumerg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

OBJSDIR = obj/

SRCS = main.c \
	   exec_routine.c \
	   libft_utils_two.c \
	   libft_utils.c \
	   philo_init_utils.c \
	   philo_init.c \
	   philo_routine.c \
	   philo_time.c \
	   verif_utils.c \
	   verif.c

OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

FLAGS = -Wall -Werror -Wextra -g

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "✅ Compiled"

$(OBJSDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $< -c -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -Rf $(OBJSDIR)
	@echo "🧹 Cleaned"

re: fclean all

.PHONY: clean all re fclean
