/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:28:26 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/31 15:45:00 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_routine(t_philo *philo, t_enum state)
{
	int						time;
	static pthread_mutex_t	print = {0};

	time = get_time_ms() - philo->st_time;
	pthread_mutex_lock(&print);
	printf ("\033[1;35;3m%d \033[0m", time);
	printf ("\033[1;34;3m%u \033[0m", philo->id);
	if (state == FORK)
		printf ("\033[1;30;3mhas taken a fork\033[0m\n");
	if (state == DEAD)
		printf ("\033[5;31;3mdied\033[0m\n");
	if (state == EAT)
		printf ("\033[1;35;3mis eating\033[0m\n");
	if (state == SLEEP)
		printf ("\033[1;36;3mis sleeping\033[0m\n");
	if (state == THINK)
		printf ("\033[1;33;3mis thinking\033[0m\n");
	pthread_mutex_unlock(&print);
}
