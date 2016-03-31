/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:23:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/31 17:45:55 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_param(const char *format)
{
	int i;
	int result;
	int j;

	j = 0;
	result = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (ft_isdigit(format[i]) || format[i] == ' ')
				i++;
		}
		if (format[i] == '%')
			i++;
		else if (format[i] == 'd' || format[i] == 'c' || format[i] == 's'
				|| format[i] == 'o' || format[i] == 'x' || format[i] == 'X'
				|| format[i] == 'i')
			result++;
		i++;
	}
	return (result);
}

t_lst	*pre_calc(const char *format, t_env1 *env1)
{
	t_env2	env2;
	ft_init_env_printf(&env2);
	env2.j = env1->taille_f;
	while (format[env1->taille_f] && format[env1->taille_f] != '%')
		env1->taille_f += 1;
	env2.str = ft_memalloc(env1->taille_f + 1);
	env2.str = ft_memcpy(env2.str, &format[env2.j], env1->taille_f - env2.j);
	ft_list_push_back(&env1->list, env2.str);
	free(env2.str);
	env2.str = NULL;
	if (format[env1->taille_f] == '%')
		ft_printf_calc(format, env1, &env2);
	return (env1->list);
}


int		ft_printf(const char *format, ...)
{
	t_env1	env;

	env.list = NULL;
	env.taille_f = 0;
	env.taille = 0;
	va_start(env.vl, format);
	env.nb_param = count_param(format);
	while (env.nb_param > 0)
	{
		env.list = pre_calc(format, &env);
		if (format[env.taille_f] != '%')
			env.nb_param--;
		if (format[env.taille_f] != '\0')
			env.taille_f++;
	}
	if (format[env.taille_f] != '\0')
		env.list = pre_calc(format, &env);
	env.tmp = env.list;
	env.str = ft_strdup("\0");
	while (env.tmp)
	{
		env.temp = env.str;
		env.str = ft_strjoin(env.str, env.tmp->str);
		free(env.temp);
		env.tmp = env.tmp->next;
	}
	ft_putstr(env.str);
	while (env.list)
	{
		env.taille += env.list->size;
		env.list = env.list->next;
	}
	va_end(env.vl);
	return (env.taille);
}
