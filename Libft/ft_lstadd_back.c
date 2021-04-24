/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:55:13 by vwinfred          #+#    #+#             */
/*   Updated: 2021/04/07 18:55:16 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		lst = &tmp->next;
	}
	*lst = new;
}
