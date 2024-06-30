/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:44:51 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/16 19:32:08 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_store_num(long int num, char *str, int is_negative)
{
	int	mod;
	int	index;

	if (num < 10)
	{
		if (is_negative && num != 0)
		{
			str[0] = '-';
			str[1] = num + '0';
			return (2);
		}
		str[0] = num + '0';
		return (1);
	}
	index = ft_store_num(num / 10, str, is_negative);
	mod = num % 10;
	str[index] = mod + '0';
	return (index + 1);
}

static int	ft_find_len(long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			is_negative;
	long int	num;
	char		*result;

	num = (long int)n;
	result = (char *)malloc(sizeof(char) * ft_find_len(num) + 1);
	if (!result)
		return ((void *)0);
	if (num < 0)
	{
		is_negative = 1;
		num *= -1;
	}
	else
		is_negative = 0;
	result[ft_store_num(num, result, is_negative)] = '\0';
	return (result);
}
