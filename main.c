/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:09:55 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/18 00:08:49 by ajubert          ###   ########.fr       */
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
	ft_printf("%10%\n{%10s}\n%d\n%cuydfff%o", "fgjh;", 23, 'l', i);
	printf("\n");
	//ft_putnbr(ft_printf("%c", 0));
	ft_printf("\n");
	printf("{%10.8d}" ,42);
	printf("\n");
	printf("{%10.2s}" ,"plop");
	printf("\n");
	printf("% .4d" ,42);
	printf("\n");
	printf("%4.d" ,42);
	printf("\n");
	ft_putnbr(printf("%.c" ,0));
	printf("\n");
	printf("%10%");
	printf("\n");
	ft_printf("%c", 'c');
	ft_printf("%o", 10);
	ft_printf("test");
	printf("\n");
	ft_printf("{%3c}");
	printf("\n");
	printf("{%3c}");
	return (0);
}
