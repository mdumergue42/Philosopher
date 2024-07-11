/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:05:46 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/12 00:42:17 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//proto arg : nb_philo tps_die ** tps_eat ** tps_sleep ** [nb_fois_philo_doit_manger]

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 5)
		return (err_message(PHILO, ERR_ARG));
	return (0);
}