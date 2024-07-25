# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 00:49:22 by madumerg          #+#    #+#              #
#    Updated: 2024/07/25 15:36:58 by madumerg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

OBJSDIR = obj/

SRCS = main.c \
	   libft_utils.c \
	   libft_utils_two.c \
	   philo_init.c \
	   philo_routine.c \
	   verif_utils.c \
	   verif.c \
	   philo_time.c

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