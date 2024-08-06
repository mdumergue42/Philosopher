/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:43:26 by madumerg          #+#    #+#             */
/*   Updated: 2024/08/03 18:49:03 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
