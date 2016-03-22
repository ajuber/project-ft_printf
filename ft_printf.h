/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:42:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/22 19:30:11 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct		s_lst
{
	char			*str;
	int				size;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env1
{
	va_list			vl;
	int				nb_param;
	int				taille;
	int				taille_f;
	t_lst			*list;
	t_lst			*tmp;
	char			*str;
	char			*temp;
}					t_env1;

typedef struct		s_env2
{
	int				j;
	char			*str;
	char			c;
	char			*tmp;
	int				result;
	int				quot;
	int				reste;
	t_lst			*tmp1;
	int				taille_min;
	int				count_space;
	int				precision;
	int				val_precision;
	int				dieze;
	int				plus;
	int				moins;
	int				test;
}					t_env2;

int		ft_printf(const char *format, ...);
void	ft_list_push_back(t_lst **begin_list, char *str);
void	ft_flags(const char *format, t_env1 *env1, t_env2 *env2);
void	ft_tri_list(t_lst **begin_list);

#endif
