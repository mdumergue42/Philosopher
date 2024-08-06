/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:18:50 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 07:40:08 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	err_message(char *str, char *av, char *strb)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd(" ", 2);
	ft_putendl_fd(strb, 2);
	return (1);
}

long long int	ft_strlen_specific(char *str)
{
	long long int	i;
	long long int	cpt;

	i = 0;
	cpt = 0;
	while (str[i] == '0' || str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		cpt++;
		i++;
	}
	return (cpt);
}

int	ft_check_overflow(char *len_num)
{
	if (ft_strlen_specific(len_num) > 11)
		return (1);
	if (ft_atoll(len_num) == 0)
		return (1);
	if (ft_atoll(len_num) > 2147483647 || ft_atoll(len_num) < -2147483648)
		return (1);
	return (0);
}
