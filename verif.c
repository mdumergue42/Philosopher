/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:10:36 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 07:41:45 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	verif_args(char **av)
{
	int	j;
	int	i;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (ft_isdigit(av[j][i]) == 1 && av[j][i] != '+')
				return (err_message(PHILO, av[j], O_NUM));
			i++;
		}
		if (ft_check_overflow(av[j]) == 1)
			return (err_message(PHILO, av[j], ERR_NUM));
		j++;
	}
	j = 1;
	return (0);
}
