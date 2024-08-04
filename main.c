/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:05:46 by madumerg          #+#    #+#             */
/*   Updated: 2024/08/03 19:03:18 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_rules(t_rules *rules, char **av, int ac)
{
	rules->nb_p = ft_atoi(av[1]);
	rules->t_death = ft_atoi(av[2]);
	rules->t_eat = ft_atoi(av[3]);
	rules->t_sleep = ft_atoi(av[4]);
	rules->nb_meal = -1;
	if (ac == 6)
		rules->nb_meal = ft_atoi(av[5]);
	return (0);
}

int	main(int ac, char **av)
{
	t_rules	*rules;

	if (ac < 5 || ac > 6)
		return (err_message(PHILO, NULL, ERR_ARG));
	if (verif_args(av) == 1)
		return (1);
	rules = ft_calloc(sizeof(t_rules), 1);
	if (!rules)
		return (1);
	philo_init(av, rules, ac);
	return (0);
}
