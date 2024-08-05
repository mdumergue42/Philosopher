/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:28:26 by madumerg          #+#    #+#             */
/*   Updated: 2024/08/04 20:15:31 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_routine(t_philo *p, t_enum state)
{
	uint32_t						time;
	static pthread_mutex_t			print = {0};
	struct timeval					actual;

	gettimeofday(&actual, NULL);
	time = get_time_ms(p->st_time, actual);
	pthread_mutex_lock(&print);
	if (get_set_end(p->rules, NO_MODIFIED) == false)
	{
		if (state == FORK)
			printf ("\033[1;30;3m%u %u has taken a fork\033[0m\n", time, p->id);
		if (state == DEAD)
			printf ("\033[5;31;3m%u %u died\033[0m\n", time, p->id);
		if (state == EAT)
			printf ("\033[1;35;3m%u %u is eating\033[0m\n", time, p->id);
		if (state == SLEEP)
			printf ("\033[1;36;3m%u %u is sleeping\033[0m\n", time, p->id);
		if (state == THINK)
			printf ("\033[1;33;3m%u %u is thinking\033[0m\n", time, p->id);
	}
	pthread_mutex_unlock(&print);
}
