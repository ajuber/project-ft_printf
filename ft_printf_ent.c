/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:37:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/31 20:11:40 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_ent(t_env1 *env1, t_env2 *env2)
{
	//char	c;
	//int		i;

	//env2->test = 0;
	//c = ' ';
	env2->result = (va_arg(env1->vl, int));
	if (env2->plus && env2->result >= 0)
		env2->str = ft_strdup("+");
	else
		env2->str = ft_strdup("\0");
	env2->tmp = env2->str;
	env2->str = ft_strjoin(env2->str, ft_itoa(env2->result));
	free(env2->tmp);/*
	env2->str = ft_itoa(env2->result);
	if (env2->precision && env2->val_precision > 0)
	{
		env2->j = 0;
		env2->tmp = ft_memalloc(env2->val_precision - ft_strlen(env2->str) + 1);
		while ((size_t)env2->j < env2->val_precision - ft_strlen(env2->str))
		{
			env2->tmp[env2->j] = '0';
			env2->j++;
		}
		env2->str = ft_strjoin(env2->tmp , env2->str);
		if (env2->result < 0)
		{
			i = 0;
			while (env2->str[i] != '-')
				i++;
			ft_swap_char(&env2->str[0], &env2->str[i]);
		}
	}
	if (env2->taille_min != 0 && (size_t)env2->taille_min > ft_strlen(env2->str))
	{
		env2->test = 1;
		if (env2->zero)
			c = '0';
		env2->tmp = ft_memalloc(env2->taille_min);
		env2->tmp = ft_strjoin(ft_memset(ft_memalloc(env2->taille_min - ft_strlen(env2->str) + 1), c, env2->taille_min - ft_strlen(env2->str)), env2->str);
		if (env2->result < 0 && c == '0')
		{
			i = 0;
			while (env2->tmp[i] != '-')
				i++;
			ft_swap_char(&env2->tmp[0], &env2->tmp[i]);
		}
		free(env2->str);
		env2->str = ft_strdup(env2->tmp);
	}
	i = 0;
	if (env2->plus && env2->result >= 0)
	{
		if (env2->test == 0)
			env2->str = ft_strjoin("+", env2->str);
		else
		{
			while (!(ft_isdigit(env2->str[i + 1])))
				i++;
			env2->str[i] = '+';
		}
	}*/
	ft_list_push_back(&env1->list, env2->str);
}
