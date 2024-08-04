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
