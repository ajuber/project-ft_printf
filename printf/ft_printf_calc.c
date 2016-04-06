/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 00:34:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/31 15:39:59 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_calc(const char *format, t_env1 *env1, t_env2 *env2)
{
	env1->taille_f += 1;
	ft_before_modif_longueur(format, env1, env2);
	if (format[env1->taille_f] == '%')
		ft_list_push_back(&env1->list, "%");
	else if (format[env1->taille_f] == 'c')
		ft_printf_ch(env1, env2);
	else if (format[env1->taille_f] == 's')
		ft_print_string(env1, env2);
	else if (format[env1->taille_f] == 'd' || format[env1->taille_f] == 'i')
		ft_printf_ent(env1, env2);
	else if (format[env1->taille_f] == 'o')
		ft_printf_octal(env1, env2);
	else if (format[env1->taille_f] == 'x' || format[env1->taille_f] == 'X')
		ft_printf_hexa(format, env1, env2);
	else if (format[env1->taille_f] == 'p')
		ft_printf_p(env1, env2);
	//else if (format[env1->taille_f] == 'C')
	//	ft_printf_C(env1, env2);
	if (env2->precision)
		ft_printf_precision(format, env1, env2);
	if (env2->taille_min != 0)
		ft_printf_taille_min(env1, env2);
}
