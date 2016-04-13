/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 00:34:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/13 18:28:24 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_conv(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (env2->modif == L || format[env1->taille_f] == 'D')
		env2->argument = va_arg(env1->vl, long);
	else if (env2->modif == HH)
		env2->argument = (char)va_arg(env1->vl, int);
	else if (env2->modif == H)
		env2->argument = (short)va_arg(env1->vl, int);
	else if (env2->modif == LL)
		env2->argument = va_arg(env1->vl, long long);
	else if (env2->modif == J)
		env2->argument = va_arg(env1->vl, intmax_t);
	else if (env2->modif == Z)
		env2->argument = va_arg(env1->vl, ssize_t);
	else
		env2->argument = va_arg(env1->vl, int);
}

void	unsigned_conv(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (env2->modif == L || ft_strchr("OU", format[env1->taille_f]))
		env2->argument1 = va_arg(env1->vl, unsigned long);
	else if (env2->modif == HH)
		env2->argument1 = (unsigned char)va_arg(env1->vl, unsigned int);
	else if (env2->modif == H)
		env2->argument1 = (unsigned short)va_arg(env1->vl, unsigned int);
	else if (env2->modif == LL)
		env2->argument1 = va_arg(env1->vl, unsigned long long);
	else if (env2->modif == J)
		env2->argument1 = va_arg(env1->vl, uintmax_t);
	else if (env2->modif == Z)
		env2->argument1 = va_arg(env1->vl, size_t);
	else
		env2->argument1 = va_arg(env1->vl, unsigned int);
}

void	printf_num(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (ft_strchr("diD", format[env1->taille_f]))
		signed_conv(format, env1, env2);
	else
		unsigned_conv(format, env1, env2);
	if (ft_strchr("diDuU", format[env1->taille_f]))
		ft_printf_ent(format, env1, env2);
	else if (ft_strchr("oO", format[env1->taille_f]))
		ft_printf_octal(env1, env2);
	else if (ft_strchr("xX", format[env1->taille_f]))
		ft_printf_hexa(format, env1, env2);
	//else if (format[env1->taille_f] == 'p')
	//	ft_printf_p(env1, env2);
}

void	printf_str(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (env2->modif == L || ft_strchr("CS", format[env1->taille_f]))
	{
		if (ft_strchr("cC", format[env1->taille_f]))
			ft_printf_C(format, env1, env2);
	//	else if (ft_strchr("sS", format[env1->taille_f]))
	//		ft_printf_S(env1, env2);
	}
	else
	{
		if (format[env1->taille_f] == 'c')
			ft_printf_ch(env1, env2);
		else if (format[env1->taille_f] == 's')
			ft_print_string(env1, env2);
	}
}

void	ft_printf_calc(const char *format, t_env1 *env1, t_env2 *env2)
{
	env1->taille_f += 1;
	ft_before_modif_longueur(format, env1, env2);
	ft_modif_longueur(format, env1, env2);
	if (format[env1->taille_f] == '%')
		ft_list_push_back(&env1->list, "%");
	if (ft_strchr("idDoOuUxX", format[env1->taille_f]))
		printf_num(format, env1, env2);
	else if (format[env1->taille_f] == 'p')
		ft_printf_p(env1, env2);
	else
		printf_str(format, env1, env2);
}
