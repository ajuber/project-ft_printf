/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:56:09 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/08 02:08:10 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(t_env1 *env1, t_env2 *env2)
{
	env2->tmp1 = NULL;
	env2->quot_p = va_arg(env1->vl, void *);
	env2->quot_po = (unsigned long)env2->quot_p;
	env2->str = ft_memalloc(2);
	while (env2->quot_po > 0)
	{
		env2->result = 0;
		env2->reste = env2->quot_po % 16;
		env2->quot_po = env2->quot_po / 16;
		if (env2->reste >= 10)
		{
			while (env2->reste != 10 + env2->result)
				env2->result++;
			env2->c = 'a' + env2->result;
			env2->str[0] = env2->c;
			ft_list_push_back(&env2->tmp1, env2->str);
		}
		else
			ft_list_push_back(&env2->tmp1, ft_itoa(env2->reste));
	}
	ft_tri_list(&env2->tmp1);
	env2->str = ft_strdup("\0");
	while (env2->tmp1)
	{
		env2->str = ft_strjoin(env2->str, env2->tmp1->str);
		env2->tmp1 = env2->tmp1->next;
	}
	env2->str = ft_strjoin("0x", env2->str);
	ft_list_push_back(&env1->list, env2->str);
}
