/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:48:37 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/31 20:56:08 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

uint32_t	get_actual_time_ms(void) //heure qu'il est
{
	struct timeval st;

	gettimeofday(&st, NULL);
	return (st.tv_sec * 1000 + st.tv_usec / 1000);
}

uint32_t	get_time_ms(struct timeval st, struct timeval actual)
{
	return (((actual.tv_sec - st.tv_sec) * 1000000 + actual.tv_usec - st.tv_usec) / 1000);
}

int	sleep_time(t_philo *philo, uint32_t ms) //temps qu'il doit dormir
{
	uint32_t	end;
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	end = get_actual_time_ms() + ms;
	while (get_actual_time_ms() < end)
	{
		gettimeofday(&actual, NULL);
		if (get_time_ms(philo->st_eat, actual) > philo->rules->t_death)
			return (1);
		usleep(1000);
	}
	return (0);
}
