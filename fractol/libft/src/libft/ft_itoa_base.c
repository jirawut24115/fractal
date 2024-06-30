/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:44:51 by jichompo          #+#    #+#             */
/*   Updated: 2024/05/20 20:31:10 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_store_num(long int num, char *str, int is_negative, int base)
{
	int	mod;
	int	index;

	if (num < base)
	{
		if (is_negative && num != 0)
		{
			str[0] = '-';
			str[1] = HEX[num];
			return (2);
		}
		str[0] = HEX[num];
		return (1);
	}
	index = ft_store_num(num / base, str, is_negative, base);
	mod = num % base;
	str[index] = HEX[mod];
	return (index + 1);
}

static int	ft_find_len(long int num, int base)
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
		num /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int n, int base)
{
	int			is_negative;
	long int	num;
	char		*result;

	num = (long int)n;
	result = (char *)malloc(sizeof(char) * ft_find_len(num, base) + 1);
	if (!result)
		return ((void *)0);
	if (num < 0)
	{
		is_negative = 1;
		num *= -1;
	}
	else
		is_negative = 0;
	result[ft_store_num(num, result, is_negative, base)] = '\0';
	return (result);
}
