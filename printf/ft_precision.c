/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 20:21:30 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/21 11:13:06 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(t_env2 *env2, int size_str)
{
	int i;

	env2->j = 0;
	env2->tmp = ft_memalloc(env2->val_precision - size_str + 1);
	while (env2->j < env2->val_precision - size_str)
	{
		env2->tmp[env2->j] = '0';
		env2->j++;
	}
	env2->str = ft_strjoin(env2->tmp, env2->str);
	if (env2->argument < 0)
	{
		i = 0;
		while (env2->str[i] != '-')
			i++;
		ft_swap_char(&env2->str[0], &env2->str[i]);
	}
}
