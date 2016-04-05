/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:42:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/31 17:24:02 by ajubert          ###   ########.fr       */
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
	wchar_t			C;
	int				result;
	unsigned int	quot;
	void			*quot_p;
	unsigned long	quot_po;
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
	int				zero;
}					t_env2;

int		ft_printf(const char *format, ...);
void	ft_list_push_back(t_lst **begin_list, char *str);
void	ft_flags(const char *format, t_env1 *env1, t_env2 *env2);
void	ft_tri_list(t_lst **begin_list);
void	ft_init_env_printf(t_env2 *env2);
void	ft_before_modif_longueur(const char *format, t_env1 *env1, t_env2 *env2);
void	ft_printf_ch(t_env1 *env1, t_env2 *env2);
void	ft_print_string(t_env1 *env1, t_env2 *env2);
void	ft_printf_ent(t_env1 *env1, t_env2 *env2);
void	ft_printf_octal(t_env1 *env1, t_env2 *env2);
void	ft_printf_hexa(const char *format, t_env1 *env1, t_env2 *env2);
void	ft_printf_precision(const char *format, t_env1 *env1, t_env2 *env2);
void	ft_printf_taille_min(t_env1 *env1, t_env2 *env2);
void	ft_printf_calc(const char *format, t_env1 *env1, t_env2 *env2);
void	ft_printf_p(t_env1 *env1, t_env2 *env2);
void	ft_printf_C(t_env1 *env1, t_env2 *env2);

#endif
