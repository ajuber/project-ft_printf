/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:09:55 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/17 19:25:40 by ajubert          ###   ########.fr       */
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
	ft_printf("%10%\n{%10s}\n%d\n%cuydfff%orebgu", "fgjh;", 23, 'l', i);
	printf("\n");
	//ft_putnbr(ft_printf("%c", 0));
	printf("{%10d}" ,42);
	printf("\n");
	printf("{%10s}" ,"plop");
	printf("\n");
	printf("% .4d" ,42);
	printf("\n");
	printf("%4.d" ,42);
	printf("\n");
	ft_putnbr(printf("%.c" ,0));
	printf("\n");
	printf("%10%");
	printf("\n");
	return (0);
}
