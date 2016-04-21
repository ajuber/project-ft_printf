/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 06:14:46 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/21 08:56:58 by ajubert          ###   ########.fr       */
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
	env2->str = ft_strdup("\0");
	while (i < size)
	{
		ft_printf_wint(env2, env2->wstr[i]);
		i++;
	}
}

void	ft_printf_wc(const char *format, t_env1 *env1, t_env2 *env2)
{
	env2->wint = va_arg(env1->vl, wint_t);
	if (env2->wint <= -1 || env2->wint > 1114111)
		ft_printf_error("Wrong wide char");
	if (env2->wint > 55296 && env2->wint < 57343)
		ft_printf_error("Wrong wide char");
	env2->wchar = (wchar_t)env2->wint;
	env2->wstr = &env2->wchar;
	if (env2->wint != 0)
		print_wchar(format, env1, env2, 1);
	else
		ft_printf_ch_null(env1, env2);
	ft_list_push_back(&env1->list, env2->str);
}

void	ft_printf_ws(const char *format, t_env1 *env1, t_env2 *env2)
{
	env2->wstr = va_arg(env1->vl, wchar_t *);
	if (!env2->wstr)
	{
		env2->str = NULL;
		ft_print_string(format, env1, env2);
		return ;
	}
	print_wchar(format, env1, env2, ft_wstrlen(env2->wstr));
	ft_list_push_back(&env1->list, env2->str);
}
