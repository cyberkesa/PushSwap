/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 03:10:25 by vwinfred          #+#    #+#             */
/*   Updated: 2021/01/17 03:10:27 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_atoi(const char *str)
{
	unsigned long	result;
	size_t			i;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return ((int)(result));
}
 