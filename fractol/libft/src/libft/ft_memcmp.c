/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:25:09 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/08 21:42:00 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;
	size_t			index;

	if (n == 0 || s1 == s2)
		return (0);
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (*(d1 + index) != *(d2 + index))
			return (*(d1 + index) - *(d2 + index));
		index++;
	}
	return (0);
}
