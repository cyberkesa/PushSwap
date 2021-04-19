/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:55:59 by vwinfred          #+#    #+#             */
/*   Updated: 2021/04/07 18:56:00 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
     Итерирует список ’lst’ и применяет функцию ’F’ к содержанию каждого элемента.
     Создает новый список в результате последовательных применений функции ’f’.
     Функция ’del’ используется для удаления содержимого элемента, если это необходимо.
 */

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_list;
	t_list		*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = NULL;
	new_list = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
