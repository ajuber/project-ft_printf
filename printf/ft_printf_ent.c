/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:37:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/09 22:50:00 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_ent(const char *format, t_env1 *env1, t_env2 *env2)
{
	char	c;
	int		i;
	int		size_str;

	env2->test = 0;
	c = ' ';
	if (ft_strchr("diD", format[env1->taille_f]))
		env2->str = ft_itoa_long_long(env2->argument);
	else
		env2->str = ft_unsigned_long_itoa(env2->argument1);
	size_str = ft_strlen(env2->str);
	if (env2->argument < 0)
		size_str--;
	if (env2->val_precision > size_str)
		ft_precision(env2, size_str);
	if (env2->taille_min != 0 && (size_t)env2->taille_min > ft_strlen(env2->str))
		ft_taille_min(env2);
	i = 0;
	if (env2->count_space && env2->argument >= 0 && !env2->precision && !env2->taille_min && !env2->plus && ft_strchr("diD", format[env1->taille_f]))
	{
		env2->tmp = env2->str;
		env2->str = ft_strjoin(" ", env2->tmp);
		free(env2->tmp);
	}
	if (env2->plus && env2->argument >= 0 && ft_strchr("diD", format[env1->taille_f]))
		ft_plus(env2);
	ft_list_push_back(&env1->list, env2->str);
}
