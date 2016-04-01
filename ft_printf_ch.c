/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:06:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/01 17:47:26 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_ch(t_env1 *env1, t_env2 *env2)
{
	env2->c = va_arg(env1->vl, int);
	if (env2->c == 0)
	{
		env2->str = ft_strdup("\0");
		ft_list_push_back(&env1->list, env2->str);
		env2->tmp1 = env1->list;
		while (env2->tmp1->next != NULL)
			env2->tmp1 = env2->tmp1->next;
		env2->tmp1->size = 1;
	}
	else
	{
		env2->str = ft_memalloc(2);
		env2->str[0] = env2->c;
		ft_list_push_back(&env1->list, env2->str);
	}
}// demi codets
