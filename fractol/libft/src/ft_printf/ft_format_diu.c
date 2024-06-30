/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:30:59 by jichompo          #+#    #+#             */
/*   Updated: 2024/05/20 20:28:02 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned_num(unsigned int num)
{
	int	result;

	result = 0;
	if (num >= 10)
	{
		result = ft_print_unsigned_num(num / 10);
		num = num % 10;
	}
	if (num < 10)
	{
		ft_putchar_fd(('0' + num), 1);
		result++;
	}
	return (result);
}

int	ft_print_num(int num)
{
	char	*s;
	int		result;

	result = 0;
	s = ft_itoa_base(num, 10);
	result += ft_putstr(s);
	free(s);
	return (result);
}
