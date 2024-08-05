/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:48:29 by madumerg          #+#    #+#             */
/*   Updated: 2024/08/04 20:15:46 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	unlock_error(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->fork_l));
	pthread_mutex_unlock(philo->fork_r);
}

void	take_forks(t_philo *philo, int id)
{
	if (id % 2)
		pthread_mutex_lock(&(philo->fork_l));
	else
		pthread_mutex_lock(philo->fork_r);
}

void	print_meals_f_part(t_philo *philo)
{
	take_forks(philo, philo->id);
	print_routine(philo, FORK);
}

void	print_meals_s_part(t_philo *philo)
{
	take_forks(philo, philo->id + 1);
	print_routine(philo, FORK);
	gettimeofday(&philo->st_eat, NULL);
	print_routine(philo, EAT);
}

void	*exec_routine(t_philo *philo)
{
	gettimeofday(&philo->st_eat, NULL);
	while (get_set_end(philo->rules, NO_MODIFIED) == false)
	{
		print_meals_f_part(philo);
		if (&philo->fork_l == philo->fork_r && \
			sleep_time(philo, philo->rules->t_death) == 1)
		{
			unlock_error(philo);
			break ;
		}
		print_meals_s_part(philo);
		if (sleep_time(philo, philo->rules->t_eat) == 1)
		{
			unlock_error(philo);
			break ;
		}
		get_set_nb_meals(philo, true);
		unlock_error(philo);
		print_routine(philo, SLEEP);
		if (sleep_time(philo, philo->rules->t_sleep) == 1)
			break ;
		print_routine(philo, THINK);
	}
	get_set_end(philo->rules, TRUE);
	return (NULL);
}
