/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:21:17 by jichompo          #+#    #+#             */
/*   Updated: 2024/05/24 01:32:17 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	index;
	size_t			s_len;

	index = 0;
	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return ((void *)0);
	while (index < len && start < s_len && *(s + start + index))
	{
		*(result + index) = *(s + start + index);
		index++;
	}
	*(result + index) = '\0';
	return (result);
}
