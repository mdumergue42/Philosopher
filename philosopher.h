/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:06:08 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/12 23:28:32 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define PHILO "philosopher : "
# define ERR_ARG "invalid number of arguments"
# define O_NUM "only numbers are accepted"
# define OVER_FLOW "number is too big"

typedef enum
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
} data_t;

typedef struct s_philo
{
	/* data */
}	t_philo;

//libft_utils.c
int				ft_isdigit(int i);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
long long int	ft_atoll(const char *str);

//utils.c
int				err_message(char *str, char *strb);
int				ft_check_overflow(char **len_num, int i);

//verif.c
int				verif_args(char **av);

#endif