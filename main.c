/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:09:55 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/15 18:30:06 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *str;
	char c;
	int i;

	i = 10;
	str = ft_strdup("ppks,l");
	c = 'c';
	//ft_printf("%%\n%s\n%d\n%cuydfff%o", "fgjd;", 23, 'l', i);
	printf("%x",i);
	return (0);
}
