/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:21:04 by madumerg          #+#    #+#             */
/*   Updated: 2024/08/04 15:21:36 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*p_routine(void *content)
{
	t_philo	*philo;

	philo = content;
	exec_routine(philo);
	return (NULL);
}

void	init_mutex(t_rules *rules)
{
	pthread_mutex_init(&(rules->mutex_lock), NULL);
	pthread_mutex_init(&(rules->death), NULL);
	rules->is_dead = false;
}

t_philo	*create_fork(t_rules *rules)
{
	t_philo			*philo;
	uint32_t		i;

	i = 0;
	philo = ft_calloc(sizeof(t_philo) + 1, rules->nb_p);
	if (!philo)
	{
		free(rules);
		return (NULL);
	}
	while (i < rules->nb_p)
	{
		pthread_mutex_init(&(philo[i].fork_l), NULL);
		philo[i].fork_r = &(philo[(i + 1) % rules->nb_p].fork_l);
		philo[i].rules = rules;
		philo[i].back_nb_meals = 0;
		philo[i].id = i + 1;
		i++;
	}
	return (philo);
}

uint32_t	philo_create(t_rules *rules, t_philo *philo)
{
	uint32_t		i;
	struct timeval	st;

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
	monitoring(philo);
	philo_join(philo, stock);
	free(rules);
	free(philo);
	return (0);
}
