/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:05:46 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/31 20:26:49 by madumerg         ###   ########.fr       */
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

//Les fonctions gettimeofday () permet d'obtenir et de définir l'heure ainsi qu'un fuseau horaire. 
//L'argument tv est une structure timeval (comme spécifié dans < sys/time.h > ) :
// structure timeval {
//     time_t tv_sec; /* secondes */
//     suseconds_t tv_usec; ​​/* microsecondes */
// };

// ***************************************************************

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
	// int n;
	// for (int i = 0; i < 10; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		n = (10 * i) + j;
	// 		printf("\e[%dm  %3d  \e[0m", n, n);
	// 	}
	// 	printf("\n");
	// }
	return (0);
}
