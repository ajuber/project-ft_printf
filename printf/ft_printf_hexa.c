/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:53:21 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/10 03:31:41 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexa(const char *format, t_env1 *env1, t_env2 *env2)
{
	int i;
	unsigned long res_arg;

	i = 0;
	res_arg = env2->argument1;
	env2->test = 1;
	env2->tmp1 = NULL;
	env2->str = ft_memalloc(2);
	while (env2->argument1 > 0 || env2->test)
	{
		env2->test = 0;
		env2->result = 0;
		env2->reste = env2->argument1 % 16;
		env2->argument1 /= 16;
		if (env2->reste >= 10)
		{
			while (env2->reste != 10 + env2->result)
				env2->result++;
			if (format[env1->taille_f] == 'x')
				env2->c = 'a' + env2->result;
			else
				env2->c = 'A' + env2->result;
			env2->str[0] = env2->c;
			ft_list_push_back(&env2->tmp1, env2->str);
		}
		else
			ft_list_push_back(&env2->tmp1, ft_unsigned_long_itoa(env2->reste));
	}
	ft_tri_list(&env2->tmp1);
	env2->str = ft_strdup("\0");
	while (env2->tmp1)
	{
		env2->str = ft_strjoin(env2->str, env2->tmp1->str);
		env2->tmp1 = env2->tmp1->next;
	}
	if ((size_t)env2->val_precision > ft_strlen(env2->str))
		ft_precision(env2, ft_strlen(env2->str));
	if (env2->precision == 1 && env2->val_precision == 0 && res_arg == 0)
		env2->str[0] = 0;
	if (env2->taille_min != 0 && (size_t)env2->taille_min > ft_strlen(env2->str))
		ft_taille_min(env2);
	if (env2->dieze && res_arg != 0)
	{
		if (format[env1->taille_f] == 'x')
		{
			if (env2->test == 0)
				env2->str = ft_strjoin("0x", env2->str);
			else
			{
				if (!env2->moins)
				{
					while (!(ft_isdigit(env2->str[i + 1]) || ft_isalpha(env2->str[i + 1])))
						i++;
					if (env2->str[i] == '0' && env2->str[i + 1] == '0')
					{
						env2->str[i] = '0';
						env2->str[i + 1] = 'x';
					}
					else if (env2->str[i] == ' ' && env2->str[i - 1] == ' ')
					{
						env2->str[i - 1] = '0';
						env2->str[i] = 'x';
					}
					else
					{
						env2->str[i] = 'x';
						env2->str = ft_strjoin("0", env2->str);
					}
				}
				else
				{
					env2->str = ft_strjoin("0x", env2->str);
					if (env2->test == 1)
						(env2->str[ft_strlen(env2->str) - 2] == ' ') ? (env2->str[ft_strlen(env2->str) - 2] = 0) : (env2->str[ft_strlen(env2->str) - 1] = 0);
				}
			}
		}
		else
		{
			if (env2->test == 0)
				env2->str = ft_strjoin("0X", env2->str);
			else
			{
				if (!env2->moins)
				{
					while (!(ft_isdigit(env2->str[i + 1]) || ft_isalpha(env2->str[i + 1])))
						i++;
					if (env2->str[i] == '0' && env2->str[i + 1] == '0')
					{
						env2->str[i] = '0';
						env2->str[i + 1] = 'X';
					}
					else if (env2->str[i] == ' ' && env2->str[i - 1] == ' ')
					{
						env2->str[i - 1] = '0';
						env2->str[i] = 'X';
					}
					else
					{
						env2->str[i] = 'X';
						env2->str = ft_strjoin("0", env2->str);
					}
				}
				else
				{
					env2->str = ft_strjoin("0X", env2->str);
					if (env2->test == 1)
						(env2->str[ft_strlen(env2->str) - 2] == ' ') ? (env2->str[ft_strlen(env2->str) - 2] = 0) : (env2->str[ft_strlen(env2->str) - 1] = 0);
				}
			}
		}
	}
	ft_list_push_back(&env1->list, env2->str);
}
