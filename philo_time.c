/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:48:37 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/30 02:26:44 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_time_ms(void) //heure qu'il est
{
	struct timeval st;

	gettimeofday(&st, NULL);
	return (st.tv_sec * 1000 + st.tv_usec / 1000);
}

void	sleep_time(int ms) //temps qu'il doit dormir
{
	int	end;

	end = get_time_ms() + ms;
	while (get_time_ms() < end)
		usleep(1000);
}
