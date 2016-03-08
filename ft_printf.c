/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:23:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/08 17:37:33 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_param(const char *format)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%')
			result++;
		i++;
	}
	return (result);
}

int		pre_calc(const char *format, va_list vl)
{
	int		i;

	i = 0;
	while (format[i] && (format[i] != '%' || (format[i] == '%' && format[i + 1] == '&')))
	{
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		ft_putchar(format[i]);
		i++;
	}
	if (format[i + 1] == 'c')
	{
		ft_putchar(va_arg(vl, int));
		return (i + 1);
	}
	return (0);
}


int		ft_printf(const char *format, ...)
{
	va_list	vl;
	int		nb_param;
	int		taille;

	taille = 0;
	va_start(vl, format);
	nb_param = count_param(format);
	while (nb_param > 0)
	{
		taille += pre_calc(format, vl);
		nb_param--;
	}
	return (taille);
}
