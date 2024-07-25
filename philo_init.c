/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:21:04 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 11:42:19 by madumerg         ###   ########.fr       */
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

void	*tamere(void)
{
	printf ("Hello World\n");
}

int	philo_create(t_rules *rules)
{
	pthread_t	t1;
	pthread_mutex_t	*mutex = NULL;
	pthread_mutex_init(&mutex, NULL);
	int	i;

	i = 0;
	while (i < rules->nb_p)
	{
		pthread_mutex_lock(mutex);
		pthread_create(&t1, NULL, &tamere, NULL);
		i++;
	pthread_mutex_unlock(mutex);
	}
	return (0);
}

int	philo_init(char **av, t_rules *rules, int ac)
{
	//struct timeval st;
//	struct timeval end;
	init_rules(rules, av, ac);
//	gettimeofday(&st, NULL);
//	print_philo(rules);
//	get_time(st, end);
	return (0);
}
