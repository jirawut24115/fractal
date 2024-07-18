/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:33:44 by jchompoo          #+#    #+#             */
/*   Updated: 2024/07/17 23:35:27 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	find_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

double	ft_atof(char *str)
{
	double	whole;
	double	dec;
	double	sign;
	double	i;

	sign = find_sign((*str));
	if (sign == -1)
		str++;
	whole = 0;
	while (*(str) && *(str) != '.')
	{
		whole = whole * 10 + (*(str) - '0');
		str++;
	}
	if (*str)
		str++;
	dec = 0;
	i = 1;
	while (*str)
	{
		i /= 10;
		dec = dec * 10 + (*(str) - '0');
		str++;
	}
	return ((whole + (dec * i)) * sign);
}
