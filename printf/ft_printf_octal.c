/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:46:40 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/09 22:51:33 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_octal(t_env1 *env1, t_env2 *env2)
{
	int		i;

	i = 0;
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
	env2->str = ft_unsigned_long_itoa(env2->result);
	if ((size_t)env2->val_precision > ft_strlen(env2->str))
		ft_precision(env2, ft_strlen(env2->str));
	if (env2->taille_min != 0 && (size_t)env2->taille_min > ft_strlen(env2->str))
		ft_taille_min(env2);
	if (env2->dieze == 1)
	{
		if (env2->test == 0)
		{
			env2->tmp = env2->str;
			env2->str = ft_strjoin("0", env2->str);
			free(env2->tmp);
		}
		else
		{
			if (!env2->moins)
			{
				while (!(ft_isdigit(env2->str[i + 1])))
					i++;
				env2->str[i] = '0';
			}
			else
			{
				env2->str = ft_strjoin("0", env2->str);
				if (env2->test == 1)
					env2->str[ft_strlen(env2->str) - 1] = 0;
			}
		}
	}
	ft_list_push_back(&env1->list, env2->str);
}
