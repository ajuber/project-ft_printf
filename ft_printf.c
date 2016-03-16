/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:23:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/16 15:26:12 by ajubert          ###   ########.fr       */
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

	j = *i;
	str = NULL;
	while (format[*i] && format[*i] != '%')
	{
		//free(str);
		*i += 1;
	}
	str = ft_memalloc(*i + 1);
	str = ft_memcpy(str, &format[j], *i - j);
	ft_list_push_back(&list, str);
	if (format[*i] == '%')
		*i += 1;
	if (format[*i] == '%')
	{
		ft_list_push_back(&list, "%");
	}
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
