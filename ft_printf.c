/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:23:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/10 17:58:28 by ajubert          ###   ########.fr       */
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

int		pre_calc(const char *format, va_list vl, int i, int *taille)
{
	int j;
	char *str;
	char *tmp;

	j = 0;
	str = NULL;
	while (format[i] && (format[i] != '%' || (format[i] == '%' && format[i + 1] == '&')))
	{
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		ft_putchar(format[i]);
		i++;
		j++;
	}
	if (format[i + 1] == 'c')
	{
		ft_putchar(va_arg(vl, int));
		*taille = *taille + j + 1;
	}
	else if (format[i + 1] == 's')
	{
		tmp = str;
		str = ft_strdup(va_arg(vl, char *));
		free(tmp);
		ft_putstr(str);
		*taille = *taille + j + ft_strlen(str);
	}
	else if (format[i + 1] == 'd')
	{
		tmp = str;
		str = ft_strdup(ft_itoa((va_arg(vl, int))));
		free(tmp);
		ft_putstr(str);
		*taille = *taille + j + ft_strlen(str);
	}
	return (i + 1);
}


int		ft_printf(const char *format, ...)
{
	va_list	vl;
	int		nb_param;
	int		taille;
	int		taille_f;
//	t_lst	*list;

	taille_f = -1;
	taille = 0;
	va_start(vl, format);
	nb_param = count_param(format);
	while (nb_param > 0)
	{
		taille_f = pre_calc(format, vl, taille_f + 1, &taille);
		nb_param--;
		ft_putnbr(taille);
	}
	return (taille);
}
