/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:54:24 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/18 06:32:38 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		index;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d)
	{
		index = (int)n - 1;
		while (index >= 0)
		{
			*(d + index) = *(s + index);
			index--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
