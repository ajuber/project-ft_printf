/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 00:01:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/24 00:04:27 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_precision(const char *format, t_env1 *env1, t_env2 *env2)
{
	env2->tmp1 = env1->list;
	while (env2->tmp1->next != NULL)
		env2->tmp1 = env2->tmp1->next;
	if (env2->val_precision < env2->tmp1->size && format[env1->taille_f] == 's')
	{
		ft_bzero(&env2->tmp1->str[env2->val_precision], ft_strlen(&env2->tmp1->str[env2->val_precision]));
		env2->tmp1->size = ft_strlen(env2->tmp1->str);
	}
	if (env2->val_precision > env2->tmp1->size && (format[env1->taille_f] == 'd' || format[env1->taille_f] == 'o'))
	{
		env2->j = 0;
		env2->tmp = ft_memalloc(env2->val_precision - env2->tmp1->size + 1);
		while (env2->j < env2->val_precision - env2->tmp1->size)
		{
			env2->tmp[env2->j] = '0';
			env2->j++;
		}
		env2->tmp1->str = ft_strjoin(env2->tmp, env2->tmp1->str);
		env2->tmp1->size = ft_strlen(env2->tmp1->str);
	}
}
