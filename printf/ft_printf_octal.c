/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:46:40 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/08 03:43:14 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_octal(t_env1 *env1, t_env2 *env2)
{
	env2->test = 1;
	env2->result = 0;
	env2->j = 0;
	while (env2->argument1 > 0 || env2->test)
	{
		env2->test = 0;
		env2->reste = env2->argument1 % 8;
		env2->argument1 /= 8;
		env2->result = env2->result + (env2->reste * (ft_iterative_power(10 , env2->j)));
		env2->j++;
	}
	if (env2->modif == LL || env2->modif == J)
		env2->str = ft_unsigned_long_itoa(env2->result);
	else
		env2->str = ft_unsigned_itoa(env2->result);
	if (env2->dieze == 1)
	{
		env2->tmp = env2->str;
		env2->str = ft_strjoin("0", env2->str);
		free(env2->tmp);
	}
	ft_list_push_back(&env1->list, env2->str);
}
