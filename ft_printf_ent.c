/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:37:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/23 23:41:46 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_ent(t_env1 *env1, t_env2 *env2)
{
	env2->result = (va_arg(env1->vl, int));
	if (env2->plus && env2->result >= 0)
		env2->str = ft_strdup("+");
	else
		env2->str = ft_strdup("\0");
	env2->tmp = env2->str;
	env2->str = ft_strjoin(env2->str, ft_itoa(env2->result));
	free(env2->tmp);
	ft_list_push_back(&env1->list, env2->str);
}
