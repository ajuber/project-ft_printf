/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:53:21 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/23 23:56:16 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexa(const char *format, t_env1 *env1, t_env2 *env2)
{
	env2->test = 1;
	env2->tmp1 = NULL;
	env2->quot = va_arg(env1->vl, int);
	while (env2->quot > 0 || env2->test)
	{
		env2->test = 0;
		env2->result = 0;
		env2->reste = env2->quot % 16;
		env2->quot /= 16;
		env2->str = ft_memalloc(2);
		if (env2->reste >= 10)
		{
			while (env2->reste != 10 + env2->result)
				env2->result++;
			if (format[env1->taille_f] == 'x')
				env2->c = 'a' + env2->result;
			else
				env2->c = 'A' + env2->result;
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
	if (env2->dieze && env2->str[0] != '0')
	{
		if (format[env1->taille_f] == 'x')
			env2->str = ft_strjoin("0x", env2->str);
		else
			env2->str = ft_strjoin("0X", env2->str);
	}
	ft_list_push_back(&env1->list, env2->str);
}
