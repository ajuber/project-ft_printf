/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:23:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/17 23:54:50 by ajubert          ###   ########.fr       */
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
		else if (format[i] == 'd' || format[i] == 'c' || format[i] == 's' || format[i] == 'o')
			result++;
		i++;
	}
	return (result);
}
/*
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
 }*/

t_lst	*pre_calc(const char *format, va_list vl, int *i, t_lst *list)
{
	int		j;
	char	*str;
	char	c;
	char	*tmp;
	int		result;
	int		quot;
	int		reste;
	t_lst	*tmp1;
	int		taille_min;
	int		count_space;
	int		precision;
	int		val_precision;

	precision = 0;
	val_precision = 0;
	j = *i;
	str = NULL;
	count_space = 0;
	taille_min = 0;
	while (format[*i] && format[*i] != '%')
		*i += 1;
	str = ft_memalloc(*i + 1);
	str = ft_memcpy(str, &format[j], *i - j);
	ft_list_push_back(&list, str);
	if (format[*i] == '%')
	{
		*i += 1;
		if (format[*i] == ' ')
			while (format[*i] == ' ')
			{
				*i += 1;
				count_space++;
			}
		if (ft_isdigit(format[*i]))
		{
			taille_min = ft_atoi(&format[*i]);
			while (ft_isdigit(format[*i]))
				*i += 1;
		}
		if (format[*i] == '%')
			ft_list_push_back(&list, "%");
		else if (format[*i] == 'c')
		{
			c = va_arg(vl, int);
			if (c == 0)
			{
				ft_list_push_back(&list, str);
				tmp1 = list;
				while (tmp1->next != NULL)
					tmp1 = tmp1->next;
				tmp1->size = 1;
			}
			else
			{
				str = ft_memalloc(2);
				str[0] = c;
				ft_list_push_back(&list, str);
			}
		}
		else if (format[*i] == 's')
		{
			tmp = str;
			str = ft_strdup(va_arg(vl, char *));
			//free(tmp);
			ft_list_push_back(&list, str);
		}
		else if (format[*i] == 'd' || format[*i] == 'i')
		{
			tmp = str;
			str = ft_strdup(ft_itoa((va_arg(vl, int))));
			//free(tmp);
			ft_list_push_back(&list, str);
		}/*
			else if (format[*i + 1] == 'p')
			{
			str = va_arg(vl, char *);
			tmp = ft_strdup(&str[0]);
			ft_list_push_back(&list, str);
		  *i += 1;
		  }*/
		else if (format[*i] == 'o')
		{
			result = 0;
			quot = va_arg(vl, int);
			j = 0;
			while (quot > 0)
			{
				reste = quot % 8;
				quot /= 8;
				result = result + (reste * (ft_iterative_power(10 , j)));
				j++;
			}
			str = ft_strdup(ft_itoa(result));
			ft_list_push_back(&list, str);
		}
		if (taille_min != 0)
		{
			tmp1 = list;
			while (tmp1->next != NULL)
				tmp1 = tmp1->next;
			if (taille_min > tmp1->size)
			{
				j = 0;
				tmp = ft_memalloc(taille_min - tmp1->size + 1);
				while (j < taille_min - tmp1->size)
				{
					tmp[j] = ' ';
					j++;
				}
				tmp1->str = ft_strjoin(tmp, tmp1->str);
				tmp1->size = ft_strlen(tmp1->str);
			}
		}
	}
	return (list);
}

int		ft_printf(const char *format, ...)
{
	va_list	vl;
	int		nb_param;
	int		taille;
	int		taille_f;
	t_lst	*list;
	t_lst	*tmp;
	char	*str;

	list = NULL;
	taille_f = 0;
	taille = 0;
	va_start(vl, format);
	nb_param = count_param(format);
	while (nb_param > 0)
	{
		list = pre_calc(format, vl, &taille_f, list);
		if (format[taille_f] != '%')
			nb_param--;
		if (format[taille_f] != '\0')
			taille_f++;
	}
	if (format[taille_f] != '\0')
		list = pre_calc(format, vl, &taille_f, list);
	tmp = list;
	str = ft_strdup("\0");
	while (tmp)
	{
		str = ft_strjoin(str, tmp->str);
		tmp = tmp->next;
	}
	ft_putstr(str);
	while (list)
	{
		taille += list->size;
		list = list->next;
	}
	va_end(vl);
	return (taille);
}
