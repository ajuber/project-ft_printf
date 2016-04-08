/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 01:23:30 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/08 04:26:37 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void	get_nb_char(unsigned long long n, int *size)
{
	while (n > 0)
	{
		n /= 10;
		*size = *size + 1;
	}
}

char		*ft_unsigned_long_itoa(unsigned long long n)
{
	int		i;
	int		size;
	char	*result;

	i = 1;
	size = 0;
	result = NULL;
	get_nb_char(n, &size);
	result = (char*)malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = 0;
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n > 0)
	{
		result[size - i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (result);
}
