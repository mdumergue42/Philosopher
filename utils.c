/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:18:50 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/12 01:10:53 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	err_message(char *str, char *strb)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(strb, 2);
	return (1);
}

int	ft_strlen_specific(char *str)
{
	int	i;
	int	cpt;

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

int	ft_check_overflow(char **len_num, int i)
{
	if (ft_strlen_specific(len_num[i]) > 11)
		return (1);
	if (ft_atoll(len_num[i]) > 2147483647 || ft_atoll(len_num[i]) < -2147483648)
		return (1);
	return (0);
}
