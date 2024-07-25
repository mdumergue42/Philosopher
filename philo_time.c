/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:48:37 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 08:57:43 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_time(struct timeval st, struct timeval end)
{
	gettimeofday(&end, NULL);
	printf ("\033[37m%ld\033[0m\n", ((end.tv_sec * 1000000 + end.tv_usec) -
    (st.tv_sec * 1000000 + st.tv_usec)));
	return (0);
}
