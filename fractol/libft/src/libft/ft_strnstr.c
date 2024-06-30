/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:30:34 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/08 17:48:23 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen((char *)little);
	while (*big && len >= little_len)
	{
		if (*big == *little
			&& (ft_memcmp(big, little, little_len) == 0))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
