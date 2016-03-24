/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:21:27 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/23 23:25:02 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(t_env1 *env1, t_env2 *env2)
{
	env2->str = ft_strdup(va_arg(env1->vl, char *));
	ft_list_push_back(&env1->list, env2->str);
}
