/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:27:49 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/09 10:09:23 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	index;
	char			*result;

	len = ft_strlen(s);
	index = 0;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return ((void *)0);
	while (index < len)
	{
		*(result + index) = f(index, *(s + index));
		index++;
	}
	*(result + index) = '\0';
	return (result);
}
