/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:15:41 by madumerg          #+#    #+#             */
/*   Updated: 2024/07/25 07:16:20 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_bzero(void *s, size_t count)
{
	memset(s, 0, count);
}

void	*ft_calloc(size_t ct, size_t size)
{
	char	*str;

	if (size == 0 || ct == 0)
		return (malloc(1));
	if ((int)size < 0 && (int)ct < 0)
		return (NULL);
	if ((unsigned long long)(size * ct) > UINT_MAX)
		return (NULL);
	str = malloc(size * ct);
	if (!str)
		return (NULL);
	ft_bzero(str, size * ct);
	return (str);
}
