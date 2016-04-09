/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:37:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/09 19:26:36 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precision(t_env2 *env2, int size_str)
{
	int i;

	env2->j = 0;
	env2->tmp = ft_memalloc(env2->val_precision - size_str + 1);
	while (env2->j < env2->val_precision - size_str)
	{
		env2->tmp[env2->j] = '0';
		env2->j++;
	}
	env2->str = ft_strjoin(env2->tmp , env2->str);
	if (env2->argument < 0)
	{
		i = 0;
		while (env2->str[i] != '-')
			i++;
		ft_swap_char(&env2->str[0], &env2->str[i]);
	}
}


void		ft_printf_ent(const char *format, t_env1 *env1, t_env2 *env2)
{
	char	c;
	int		i;
	int		size_str;

	env2->test = 0;
	c = ' ';
	if (ft_strchr("diD", format[env1->taille_f]))
	{
		if (env2->modif == LL || env2->modif == J)
			env2->str = ft_itoa_long_long(env2->argument);
		else
			env2->str = ft_itoa(env2->argument);
	}
	else
			env2->str = ft_unsigned_long_itoa(env2->argument1);
	size_str = ft_strlen(env2->str);
	if (env2->argument < 0)
		size_str--;
	if (env2->val_precision > size_str)
		ft_precision(env2, size_str);
	if (env2->taille_min != 0 && (size_t)env2->taille_min > ft_strlen(env2->str))
	{
		env2->test = 1;
		env2->tmp = ft_memalloc(env2->taille_min);
		if (!env2->moins)
		{
			if (env2->zero && !(env2->precision))
				c = '0';
			env2->tmp = ft_strjoin(ft_memset(ft_memalloc(env2->taille_min - ft_strlen(env2->str) + 1), c, env2->taille_min - ft_strlen(env2->str)), env2->str);
			if (env2->argument < 0 && c == '0')
			{
				i = 0;
				while (env2->tmp[i] != '-')
					i++;
				ft_swap_char(&env2->tmp[0], &env2->tmp[i]);
			}
		}
		else
			env2->tmp = ft_strjoin(env2->str, ft_memset(ft_memalloc(env2->taille_min - ft_strlen(env2->str) + 1), c, env2->taille_min - ft_strlen(env2->str)));
		free(env2->str);
		env2->str = ft_strdup(env2->tmp);
	}
	i = 0;
	if (env2->count_space && env2->argument >= 0 && !env2->precision && !env2->taille_min && !env2->plus && ft_strchr("diD", format[env1->taille_f]))
	{
		env2->tmp = env2->str;
		env2->str = ft_strjoin(" ", env2->tmp);
		free(env2->tmp);
	}
	if (env2->plus && env2->argument >= 0)
	{
		if (env2->test == 0)
			env2->str = ft_strjoin("+", env2->str);
		else
		{
			while (!(ft_isdigit(env2->str[i + 1])))
				i++;
			env2->str[i] = '+';
		}
	}
	ft_list_push_back(&env1->list, env2->str);
}
