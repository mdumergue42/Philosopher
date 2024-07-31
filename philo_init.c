/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:21:04 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/31 22:01:59 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_rules(t_rules *rules, char **av, int ac)
{
	rules->nb_p = ft_atoi(av[1]);
	rules->t_death = ft_atoi(av[2]);
	rules->t_eat = ft_atoi(av[3]);
	rules->t_sleep = ft_atoi(av[4]);
	rules->nb_meal = -1;
	if (ac == 6)
		rules->nb_meal = ft_atoi(av[5]);
	return (0);
}

void	take_forks(t_philo *philo, int id)
{
	if (id % 2)
		pthread_mutex_lock(&(philo->fork_l));
	else
		pthread_mutex_lock(philo->fork_r);
}

void	unlock_error(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->fork_l));
	pthread_mutex_unlock(philo->fork_r);
	print_routine(philo, DEAD);
}

void	*exec_routine(t_philo *philo, int i)
{
	while (1)
	{
		take_forks(philo, philo->id);
		print_routine(philo, FORK);
		if (&philo->fork_l == philo->fork_r)
		{
			if (sleep_time(philo, philo->rules->t_death) == 1)
			{
				unlock_error(philo);
				break ;
			}
		}
		take_forks(philo, philo->id + 1);
		print_routine(philo, FORK);
		gettimeofday(&philo->st_eat, NULL);
		print_routine(philo, EAT);
		if (sleep_time(philo, philo->rules->t_eat) == 1)
		{
			unlock_error(philo);
			break ;
		}
		pthread_mutex_unlock(&(philo->fork_l));
		pthread_mutex_unlock(philo->fork_r);
		i++;
		print_routine(philo, SLEEP);
		if (sleep_time(philo, philo->rules->t_sleep) == 1)
		{
			print_routine(philo, DEAD);
			break ;
		}
		if (i == philo->rules->nb_meal)
			break ;
		print_routine(philo, THINK);
	}
	return (NULL);
}

void	*p_routine(void *content)
{
	t_philo			*philo;

	philo = content;
	exec_routine(philo, 0);
	return (NULL);
}

void	init_mutex(t_rules *rules)
{
	pthread_mutex_init(&(rules->mutex_lock), NULL);
	rules->is_dead = false;
}

t_philo	*create_fork(t_rules *rules)
{
	t_philo			*philo;
	uint32_t		i;

	i = 0;
	philo = ft_calloc(sizeof(t_philo) + 1, rules->nb_p);
	if (!philo)
		return (NULL);
	while (i < rules->nb_p)
	{
		pthread_mutex_init(&(philo[i].fork_l), NULL);
		philo[i].fork_r = &(philo[(i + 1) % rules->nb_p].fork_l);
		philo[i].rules = rules;
		philo[i].id = i + 1;
		i++;
	}
	return (philo);
}

void	philo_join(t_philo *philo, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_join(philo[i].t2, NULL);
		i++;
	}
}

int	philo_create(t_rules *rules, t_philo *philo) //return le nb de philo creer
{
	uint32_t		i;
	struct timeval st;

	i = 0;
	init_mutex(rules);
	gettimeofday(&st, NULL);
	while (i < rules->nb_p)
	{
		philo[i].st_time = st;
		if (pthread_create(&(philo[i].t2), NULL, &p_routine, &philo[i]) != 0)
			return (i);
		i++;
	}
	return (i);
}

int	philo_init(char **av, t_rules *rules, int ac)
{
	t_philo			*philo;
	int				stock;

	init_rules(rules, av, ac);
	philo = create_fork(rules);
	stock = philo_create(rules, philo);
	philo_join(philo, stock);
	return (0);
}
