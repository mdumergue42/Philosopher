/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:06:08 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 11:33:58 by madumerg         ###   ########.fr       */
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

# define PHILO "philosopher : "
# define ERR_ARG "invalid number of arguments"
# define O_NUM "only numbers are accepted"
# define OVER_FLOW "number is too big"

typedef enum t_bool
{
	TRUE,
	FALSE
}	t_bool;

typedef struct s_rules
{
	int				nb_p;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				nb_meal;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*mutex_lock;
	t_bool			is_dead;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	t_rules			*rules;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	**tab_fork;
}	t_data;

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
void			*print_philo(t_rules *rules);

//utils.c
int				err_message(char *str, char *av, char *strb);
int				ft_check_overflow(char *len_num);

//verif.c
int				verif_args(char **av);

int	get_time(struct timeval st, struct timeval end);

#endif
