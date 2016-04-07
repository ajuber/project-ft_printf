/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_C.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:03:29 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/07 18:03:32 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_C(t_env1 *env1, t_env2 *env2)
{
	env2->C = va_arg(env1->vl, wchar_t);
	if (env2->C < -1 || env2->C > 1114111)
		return (-1);
	if (env2->C >= 55296 && env2->C <= 57343)
		return (-1);
	env2->str = ft_memalloc(2);
	env2->str[0] = env2->
}
