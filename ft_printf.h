/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:42:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/10 14:58:39 by ajubert          ###   ########.fr       */
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

int		ft_printf(const char *format, ...);

#endif
