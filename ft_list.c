/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:44:08 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/15 14:24:47 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lst	*new_lst(char *src)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->next = NULL;
	new->str = ft_strdup(src);
	new->size = ft_strlen(new->str);
	return (new);
}

void	ft_list_push_back(t_lst **begin_list, char *str)
{
	t_lst *new;
	t_lst *tmp;

	new = new_lst(str);
	if (*begin_list == NULL)
		*begin_list = new;
	else
	{
		tmp = *begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
