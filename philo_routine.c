/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:28:26 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 17:36:39 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_routine(t_philo *philo, t_enum state)
{
	int	time;

	pthread_mutex_lock(&(philo->rules->print_mutex));
	time = get_time_ms() - philo->st_time;
	printf ("\033[1;35;3m%d \033[0m", time);
	printf ("\033[1;34;3m %u \033[0m", philo->id);
	if (state == FORK)
		printf ("\033[1;30;3mhas taken a fork\n");
	if (state == DEAD)
		printf ("\033[1;31;3mdied\e[0m\n");
	if (state == EAT)
		printf ("\033[1;35;3mis eating\033[0m\n");
	if (state == SLEEP)
		printf ("\033[1;36;3mis sleeping\033[0m\n");
	if (state == THINK)
		printf ("\033[1;33;3mis thinking\033[0m\n");
	pthread_mutex_unlock(&(philo->rules->print_mutex));
}
