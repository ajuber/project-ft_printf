/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:23:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/22 20:17:32 by ajubert          ###   ########.fr       */
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
	int		dieze;

	precision = 0;
	val_precision = 0;
	j = *i;
	str = NULL;
	count_space = 0;
	taille_min = 0;
	dieze = 0;
	while (format[*i] && format[*i] != '%')
		*i += 1;
	str = ft_memalloc(*i + 1);
	str = ft_memcpy(str, &format[j], *i - j);
	ft_list_push_back(&list, str);
	if (format[*i] == '%')
	{
		*i += 1;
		if (format[*i] == '#')
			dieze = 1;
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
		if (format[*i] == '.')
		{
			*i += 1;
			precision = 1;
			if (ft_isdigit(format[*i]))
			{
				val_precision = ft_atoi(&format[*i]);
				while (ft_isdigit(format[*i]))
					*i += 1;
			}
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
		}
		//	else if (format[*i + 1] == 'p')
		//	{
		//	str = va_arg(vl, char *);
		//	tmp = ft_strdup(&str[0]);
		//	ft_list_push_back(&list, str);
		//  *i += 1;
	//	  }
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
			if (dieze == 1)
				str = ft_strjoin("0", str);
			ft_list_push_back(&list, str);
		}
		if (precision)
		{
			tmp1 = list;
			while (tmp1->next != NULL)
				tmp1 = tmp1->next;
			if (val_precision < tmp1->size && format[*i] == 's')
			{
				ft_bzero(&tmp1->str[val_precision], ft_strlen(&tmp1->str[val_precision]));
				tmp1->size = ft_strlen(tmp1->str);
			}
			if (val_precision > tmp1->size && format[*i] == 'd')
			{
				j = 0;
				tmp = ft_memalloc(val_precision - tmp1->size + 1);
				while (j < val_precision - tmp1->size)
				{
					tmp[j] = '0';
					j++;
				}
				tmp1->str = ft_strjoin(tmp, tmp1->str);
				tmp1->size = ft_strlen(tmp1->str);
			}
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
}*/

t_lst	*pre_calc(const char *format, t_env1 *env1)
{
	t_env2	env2;

	env2.precision = 0;
	env2.val_precision = 0;
	env2.j = env1->taille_f;
	env2.str = NULL;
	env2.count_space = 0;
	env2.taille_min = 0;
	env2.dieze = 0;
	env2.plus = 0;
	while (format[env1->taille_f] && format[env1->taille_f] != '%')
		env1->taille_f += 1;
	env2.str = ft_memalloc(env1->taille_f + 1);
	env2.str = ft_memcpy(env2.str, &format[env2.j], env1->taille_f - env2.j);
	ft_list_push_back(&env1->list, env2.str);
	free(env2.str);
	env2.str = NULL;
	if (format[env1->taille_f] == '%')
	{
		env1->taille_f += 1;
		if (format[env1->taille_f] == '#' || format[env1->taille_f] == ' ' || format[env1->taille_f] == '+' || format[env1->taille_f] == '-' || format[env1->taille_f] == '0')
			ft_flags(format, env1, &env2);
			/*env2.dieze = 1;
		if (format[env1->taille_f] == ' ')
			while (format[env1->taille_f] == ' ')
			{
				env1->taille_f+= 1;
				env2.count_space++;
			}*/
		if (ft_isdigit(format[env1->taille_f]))
		{
			env2.taille_min = ft_atoi(&format[env1->taille_f]);
			while (ft_isdigit(format[env1->taille_f]))
				env1->taille_f += 1;
		}
		if (format[env1->taille_f] == '.')
		{
			env1->taille_f += 1;
			env2.precision = 1;
			if (ft_isdigit(format[env1->taille_f]))
			{
				env2.val_precision = ft_atoi(&format[env1->taille_f]);
				while (ft_isdigit(format[env1->taille_f]))
					env1->taille_f += 1;
			}
		}
		if (format[env1->taille_f] == '%')
			ft_list_push_back(&env1->list, "%");
		else if (format[env1->taille_f] == 'c')
		{
			env2.c = va_arg(env1->vl, int);
			if (env2.c == 0)
			{
				env2.str = ft_strdup("\0");
				ft_list_push_back(&env1->list, env2.str);
				env2.tmp1 = env1->list;
				while (env2.tmp1->next != NULL)
					env2.tmp1 = env2.tmp1->next;
				env2.tmp1->size = 1;
			}
			else
			{
				env2.str = ft_memalloc(2);
				env2.str[0] = env2.c;
				ft_list_push_back(&env1->list, env2.str);
			}
		}
		else if (format[env1->taille_f] == 's')
		{
			env2.str = ft_strdup(va_arg(env1->vl, char *));
			ft_list_push_back(&env1->list, env2.str);
		}
		else if (format[env1->taille_f] == 'd' || format[env1->taille_f] == 'i')
		{
			//env2.tmp = env2.str;
			env2.result = (va_arg(env1->vl, int));
			if (env2.plus && env2.result >= 0)
				env2.str = ft_strdup("+");
			else
				env2.str = ft_strdup("\0");
			env2.tmp = env2.str;
			env2.str = ft_strjoin(env2.str, ft_itoa(env2.result));
			free(env2.tmp);
			ft_list_push_back(&env1->list, env2.str);
		}/*
			else if (format[*i + 1] == 'p')
			{
			str = va_arg(vl, char *);
			tmp = ft_strdup(&str[0]);
			ft_list_push_back(&list, str);
		  *i += 1;
		  }*/
		else if (format[env1->taille_f] == 'o')
		{
			env2.test = 1;
			env2.result = 0;
			env2.quot = va_arg(env1->vl, int);
			env2.j = 0;
			while (env2.quot > 0 || env2.test)
			{
				env2.test = 0;
				env2.reste = env2.quot % 8;
				env2.quot /= 8;
				env2.result = env2.result + (env2.reste * (ft_iterative_power(10 , env2.j)));
				env2.j++;
			}
			env2.str = ft_strdup(ft_itoa(env2.result));
			if (env2.dieze == 1)
			{
				env2.tmp = env2.str;
				env2.str = ft_strjoin("0", env2.str);
				free(env2.tmp);
			}
			ft_list_push_back(&env1->list, env2.str);
		}
		else if (format[env1->taille_f] == 'x' || format[env1->taille_f] == 'X')
		{
			env2.test = 1;
			env2.tmp1 = NULL;
			env2.quot = va_arg(env1->vl, int);
			while (env2.quot > 0 || env2.test)
			{
				env2.test = 0;
				env2.result = 0;
				env2.reste = env2.quot % 16;
				env2.quot /= 16;
				env2.str = ft_memalloc(2);
				if (env2.reste >= 10)
				{
					while (env2.reste != 10 + env2.result)
						env2.result++;
					if (format[env1->taille_f] == 'x')
						env2.c = 'a' + env2.result;
					else
						env2.c = 'A' + env2.result;
					env2.str[0] = env2.c;
					ft_list_push_back(&env2.tmp1, env2.str);
				}
				else
					ft_list_push_back(&env2.tmp1, ft_itoa(env2.reste));
			}
			ft_tri_list(&env2.tmp1);
			env2.str = ft_strdup("\0");
			while (env2.tmp1)
			{
				env2.str = ft_strjoin(env2.str, env2.tmp1->str);
				env2.tmp1 = env2.tmp1->next;
			}
			/*	if (env2.dieze)
				{
					if (format[env1->taille_f] == 'x')
						env2.str = ft_strjoin("Ox", env2.tmp1->str);
					else
						env2.str = ft_strjoin("OX", env2.tmp1->str);
				}*/
			ft_list_push_back(&env1->list, env2.str);
		}
		if (env2.precision)
		{
			env2.tmp1 = env1->list;
			while (env2.tmp1->next != NULL)
				env2.tmp1 = env2.tmp1->next;
			if (env2.val_precision < env2.tmp1->size && format[env1->taille_f] == 's')
			{
				ft_bzero(&env2.tmp1->str[env2.val_precision], ft_strlen(&env2.tmp1->str[env2.val_precision]));
				env2.tmp1->size = ft_strlen(env2.tmp1->str);
			}
			if (env2.val_precision > env2.tmp1->size && (format[env1->taille_f] == 'd' || format[env1->taille_f] == 'o'))
			{
				env2.j = 0;
				env2.tmp = ft_memalloc(env2.val_precision - env2.tmp1->size + 1);
				while (env2.j < env2.val_precision - env2.tmp1->size)
				{
					env2.tmp[env2.j] = '0';
					env2.j++;
				}
				env2.tmp1->str = ft_strjoin(env2.tmp, env2.tmp1->str);
				env2.tmp1->size = ft_strlen(env2.tmp1->str);
			}
		}
		if (env2.taille_min != 0)
		{
			env2.tmp1 = env1->list;
			while (env2.tmp1->next != NULL)
				env2.tmp1 = env2.tmp1->next;
			if (env2.taille_min > env2.tmp1->size)
			{
				env2.j = 0;
				env2.tmp = ft_memalloc(env2.taille_min - env2.tmp1->size + 1);
				while (env2.j < env2.taille_min - env2.tmp1->size)
				{
					env2.tmp[env2.j] = ' ';
					env2.j++;
				}
				if (env2.moins == 1)
					env2.tmp1->str = ft_strjoin(env2.tmp1->str, env2.tmp);
				else
					env2.tmp1->str = ft_strjoin(env2.tmp, env2.tmp1->str);
				env2.tmp1->size = ft_strlen(env2.tmp1->str);
			}
		}
	}
	return (env1->list);
}


int		ft_printf(const char *format, ...)
{/*
	va_list	vl;
	int		nb_param;
	int		taille;
	int		taille_f;
	t_lst	*list;
	t_lst	*tmp;
	char	*str;*/
	t_env1	env;

	env.list = NULL;
	env.taille_f = 0;
	env.taille = 0;
	va_start(env.vl, format);
	env.nb_param = count_param(format);
	/*while (nb_param > 0)
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
	}*/
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
