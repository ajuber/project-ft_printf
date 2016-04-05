/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:09:55 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/31 16:11:26 by ajubert          ###   ########.fr       */
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
	printf("{%10.11d}" ,42);
	printf("\n");
	printf("{%.10s}" ,"plop");
	printf("\n");
	printf("% .4d" ,42);
	printf("\n");
	printf("%-4.d" ,42);
	printf("\n");
	ft_putnbr(printf("%.c" ,0));
	printf("\n");
	printf("%10%");
	printf("\n");
	ft_printf("%.c", 'c');
	ft_printf("%o", 10);
	ft_printf("test");
	ft_printf("\n");
	ft_printf("%10.4d\n%.2s",42,"plop");
	ft_printf("\n");
	printf("%#-o", i);
	printf("\n");
	printf("%10.10d", i);
	printf("\n");
	printf("%x", -42);
	printf("\n");
	printf("%p", str);
	printf("\n");
	ft_printf("%p", str);
	printf("\n");
	printf("%x", 62927376);
	printf("\n");
	ft_printf("%x", 62927376);
	printf("\n");
	ft_putnbr(wprintf("%C", 130));
	printf("\n");
	return (0);
}
