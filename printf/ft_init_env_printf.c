/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 22:24:49 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/23 22:28:45 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_env_printf(t_env2 *env2)
{
	env2->precision = 0;
	env2->val_precision = 0;
	env2->str = NULL;
	env2->count_space = 0;
	env2->taille_min = 0;
	env2->dieze = 0;
	env2->plus = 0;
	env2->zero = 0;
}
