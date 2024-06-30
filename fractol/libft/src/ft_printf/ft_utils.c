/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:21:29 by jichompo          #+#    #+#             */
/*   Updated: 2024/05/20 20:30:51 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	result;

	result = 0;
	if (!s)
	{
		result += write (1, "(null)", 6);
		return (result);
	}
	while (*s)
	{
		result += write (1, s, 1);
		s++;
	}
	return (result);
}

// void	ft_toupper(char *s)
// {
// 	while (*s)
// 	{
// 		if (*s >= 'a' && *s <= 'z')
// 			*s -= 32;
// 		s++;
// 	}
// }

// int	ft_strlen(char *s)
// {
// 	int	result;

// 	result = 0;
// 	while (*s)
// 	{
// 		result++;
// 		s++;
// 	}
// 	return (result);
// }
