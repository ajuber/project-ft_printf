/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_taille_min.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 00:09:27 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/24 00:12:59 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_taille_min(t_env1 *env1, t_env2 *env2)
{
	env2->tmp1 = env1->list;
	while (env2->tmp1->next != NULL)
		env2->tmp1 = env2->tmp1->next;
	if (env2->taille_min > env2->tmp1->size)
	{
		env2->j = 0;
		env2->tmp = ft_memalloc(env2->taille_min - env2->tmp1->size + 1);
		while (env2->j < env2->taille_min - env2->tmp1->size)
		{
			env2->tmp[env2->j] = ' ';
			env2->j++;
		}
		if (env2->moins == 1)
			env2->tmp1->str = ft_strjoin(env2->tmp1->str, env2->tmp);
		else
			env2->tmp1->str = ft_strjoin(env2->tmp, env2->tmp1->str);
		env2->tmp1->size = ft_strlen(env2->tmp1->str);
	}
}
