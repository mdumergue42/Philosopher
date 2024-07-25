/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:28:26 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 11:33:40 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*print_philo(t_rules *rules)
{
	printf ("\033[1;33;3mnb_p = %d\033[0m\n", rules->nb_p);
	printf ("\033[1;31;3mt_death = %d\e[0m\n", rules->t_death);
	printf ("\033[1;34;3mt_eat = %d\033[0m\n", rules->t_eat);
	printf ("\033[1;35;3mt_sleep = %d\033[0m\n", rules->t_sleep);
	printf ("\033[1;36;3mnb_meal = %d\033[0m\n", rules->nb_meal);
}
