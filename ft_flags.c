/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:32 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/22 16:06:41 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (format[env1->taille_f] == '#')
		env2->dieze = 1;
	if (format[env1->taille_f] == ' ')
		env2->count_space = 1;
	if (format[env1->taille_f] == '+')
		env2->plus = 1;
	if (format[env1->taille_f] == '-')
		env2->moins = 1;
	env1->taille_f++;
	if (format[env1->taille_f] == '#' || format[env1->taille_f] == ' ' || format[env1->taille_f] == '+' || format[env1->taille_f] == '-')
		ft_flags(format, env1, env2);
}
