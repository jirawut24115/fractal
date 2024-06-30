/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:37:51 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/08 16:52:09 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (*s)
	{
		s++;
		index++;
	}
	while (index >= 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
		index--;
	}
	return ((void *)0);
}
