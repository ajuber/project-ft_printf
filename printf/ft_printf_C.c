/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_C.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:03:29 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/08 03:38:47 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_wchar(const char *format, t_env1 *env1, t_env2 *env2, int *size)
{
	int		i;
	int		var;
	int		res;

	i = 0;
	var = 0;
	res = 0;
	while (i < *size)
	{
		if (env2->wstr[i] <= 0x7F)
			var = 1;
		else if (env2->wstr[i] <= 0x7FF)
			var = 2;
		else if (env2->wstr[i] <= 0xFFFF)
			var = 3;
		else if (env2->wstr[i] <= 0x10FFFF)
			var = 4;
		if (env2->precision && format[env1->taille_f] == 'S'
				&& (res + var) > env2->val_precision)
			break ;
		res += var;
		i++;
	}
	*size = i;
	return (res);
}

void	print_wchar(const char *format, t_env1 *env1, t_env2 *env2, int size)
{
	int size_wchar;
	int i;

	size_wchar = count_wchar(format, env1, env2, &size);
	i = 0;
	while (i < size)
	{
		print
}

void	ft_printf_C(const char *format, t_env1 *env1, t_env2 *env2)
{
	env2->wint = va_arg(env1->vl, wint_t);
//	if (env2->wint <= -1 || env2->wint > 1114111)
//		printf_error("Wrong wide char");
//	if (env2->C > 55296 && env2->C < 57343)
//		printf_error("Wrong wide char");
	env2->wchar = (wchar_t)env2->wint;
	env2->wstr = &env2->wchar;
	print_wchar(format, env1, env2, 1);
}
