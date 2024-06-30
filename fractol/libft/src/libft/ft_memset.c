/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:17:22 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/03 22:57:37 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	index;
	char			*p;

	index = 0;
	p = (char *)s;
	while (index < n)
	{
		*(p + index) = c;
		index++;
	}
	return (s);
}
