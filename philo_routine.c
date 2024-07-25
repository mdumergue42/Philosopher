/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:28:26 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 09:03:49 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_philo(t_rules *rules)
{
	printf ("\033[35mnb_p = %d\033[0m\n", rules->nb_p);
	printf ("\033[55mt_death = %d\033[0m\n", rules->t_death);
	printf ("\033[34mt_eat = %d\033[0m\n", rules->t_eat);
	printf ("\033[33mt_sleep = %d\033[0m\n", rules->t_sleep);
	if (rules->nb_meal)
		printf ("\033[32mnb_meal = %d\033[0m\n", rules->nb_meal);
}
