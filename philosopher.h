/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:06:08 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/12 00:45:06 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER
# define PHILOSOPHER

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define PHILO "philosopher : "
# define ERR_ARG "invalid number of arguments"

typedef struct philo
{
	/* data */
}	t_philo;


//libft_utils.c
int		ft_isdigit(int i);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

//utils.c
int		err_message(char *str, char *strb);

#endif