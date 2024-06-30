/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:34:53 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/18 06:32:42 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	if (!dest || !src)
		return ((void *)0);
	while (index < n)
	{
		*((char *)dest + index) = *((char *)src + index);
		index++;
	}
	return (dest);
}
