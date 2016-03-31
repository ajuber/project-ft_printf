/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:44:08 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/31 16:20:08 by ajubert          ###   ########.fr       */
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

int		count_lst(t_lst **begin_list)
{
	int		result;
	t_lst	*tmp;

	result = 0;
	tmp = *begin_list;
	while (tmp)
	{
		result++;
		tmp = tmp->next;
	}
	return (result);
}

void	ft_swap_list_str(t_lst **tmp, t_lst **tmp1)
{
	char	*temp;
	t_lst	*tmp00;
	t_lst	*tmp11;

	tmp00 = *tmp;
	tmp11 = *tmp1;
	temp = ft_strdup(tmp00->str);
	tmp00->size = tmp11->size;
	tmp00->str = ft_memalloc(tmp00->size);
	tmp00->str = ft_strcpy(tmp00->str, tmp11->str);
	free(tmp11->str);
	tmp11->str = ft_strdup(temp);
	tmp11->size = ft_strlen(tmp11->str);
}

void	ft_tri_list(t_lst **begin_list)
{
	t_lst	*tmp;
	t_lst	*tmp1;
	int		size;
	int		i;
	int		j;

	i = 1;
	size = count_lst(begin_list);
	tmp = *begin_list;
	while (i <= (size / 2))
	{
		j = i + 1;
		tmp1 = tmp->next;
		while (j <= size - i)
		{
			tmp1 = tmp1->next;
			j++;
		}
		ft_swap_list_str(&tmp, &tmp1);
		tmp = tmp->next;
		i++;
	}
}
