/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:06:08 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 16:45:14 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdint.h>

# define PHILO "philosopher : "
# define ERR_ARG "invalid number of arguments"
# define O_NUM "only numbers are accepted"
# define OVER_FLOW "number is too big"

typedef enum s_enum
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_enum;

typedef struct s_rules
{
	uint32_t		nb_p;
	uint32_t		t_death;
	uint32_t		t_eat;
	uint32_t		t_sleep;
	uint32_t		nb_meal;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	mutex_lock;
	bool			is_dead;
}	t_rules;

typedef struct s_philo
{
	uint32_t		id;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
	t_rules			*rules;
	pthread_t		t2;
	int				st_time;	
}	t_philo;

//libft_utils_two.c
void			*ft_calloc(size_t ct, size_t size);

//libft_utils.c
int				ft_isdigit(int i);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
long long int	ft_atoll(const char *str);
int				ft_atoi(const char *str);

//philo_init.c
int				init_rules(t_rules *rules, char **av, int ac);
int				philo_init(char **av, t_rules *rules, int ac);

//philo_routine.c
void			print_philo(t_rules *rules);

//utils.c
int				err_message(char *str, char *av, char *strb);
int				ft_check_overflow(char *len_num);

//verif.c
int				verif_args(char **av);

int				get_time(struct timeval st, struct timeval end);
int				get_time_ms(void);
void			sleep_time(int ms);
#endif
