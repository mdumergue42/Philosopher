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
		return (NULL);
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

bool	get_set_end(t_rules *rules, t_modif_end end)
{
	bool	temp;

	pthread_mutex_lock(&(rules->death));
	if (end != NO_MODIFIED)
		rules->is_dead = end;
	temp = rules->is_dead;
	pthread_mutex_unlock(&(rules->death));
	return (temp);
}

int	get_set_nb_meals(t_philo *philo, bool set)
{
	int	temp;

	pthread_mutex_lock(&(philo->rules->death));
	if (set)
		philo->back_nb_meals++;
	temp = philo->back_nb_meals;
	pthread_mutex_unlock(&(philo->rules->death));
	return (temp);
}

bool	is_end(t_philo *philo)
{
	uint32_t	i;
	uint32_t	nb_p_meal;

	i = 0;
	nb_p_meal = 0;
	while (philo[0].rules->nb_p > i)
	{
		if (philo[0].rules->nb_meal != -1 && \
			get_set_nb_meals(&philo[i], false) >= philo[0].rules->nb_meal)
			nb_p_meal++;
		if (get_set_end(philo[i].rules, NO_MODIFIED) == true)
			return (true);
		i++;
	}
	if (nb_p_meal == philo[0].rules->nb_p)
		return (true);
	return (false);
}

void	monitoring(t_philo *philo)
{
	while (is_end(philo) == false)
		usleep(10);
	get_set_end(philo->rules, TRUE);
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
	return (0);
}
