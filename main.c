/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:05:46 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/12 23:57:49 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//proto arg : ****************************************************

//arg[1] == nb_philo
//arg[2] == tps_die
//arg[3] == tps_eat
//arg[4] == tps_sleep
//arg[5_facultatif] == [nb_fois_philo_doit_manger]

//faire un enum pour les nommer **********************************

//ft des threads autorises : *************************************

//pthread_create -> pour creer un nv thread

//pthread_detach -->  place le thread th dans l'état détaché // rien compris
// pthread_join ->  suspend l'exécution du thread appelant jusqu'à ce que le thread
//identifié par th achève son exécution, soit en appelant pthread_exit(3) soit après
//avoir été annulé.


// pthread_mutex_init -->  Un mutex peut être dans deux états : 
//déverrouillé (pris par aucun thread)
//verrouillé (appartenant à un thread).
//Un mutex ne peut être pris que par un seul thread à la fois.
//Un thread qui tente de verrouiller un mutex déjà verrouillé est suspendu
//jusqu'à ce que le mutex soit déverrouillé.
//pinitialise le mutex pointé par mutex selon les attributs de mutex spécifié par mutexattr.
//Si mutexattr vaut NULL, les paramètres par défaut sont utilisés.


//pthread_mutex_destroy -> detruit le mutex


//pthread_mutex_lock --> L'objet mutex référencé par mutex doit être verrouillé en appelant
//Si le mutex est déjà verrouillé, le thread appelant doit se
//bloquer jusqu'à ce que le mutex soit disponible.


//pthread_mutex_unlock -> doit liberer le mutex lock

// ***************************************************************

void	*test_thread_one(void *arg)
{
	(void)arg;
	int	i;

	i = 0;
	while (i < 100)
	{
		printf ("\033[92mt1 %d\033[0m\n", i);
		i++;
	}
	pthread_exit(NULL);
}

void	*test_thread_two(void *arg)
{
	(void)arg;
	int	i;

	i = 0;
	while (i < 100)
	{
		printf ("\033[95mt2 %d\033[0\n", i);
		i++;
	}
	pthread_exit(NULL);
}

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	pthread_t	t1;
	pthread_t	t2;

	// if (ac < 5 || ac > 6)
	// 	return (err_message(PHILO, ERR_ARG));
	// verif_args(av);
	pthread_create(&t1, NULL, test_thread_one, NULL);
	pthread_create(&t2, NULL, test_thread_two, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	// int i = 0;
	// while (i < 1000000000)
	// 	i++;

	return (0);
}
