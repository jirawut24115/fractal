/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:36:32 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/04 10:59:09 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	start = 0;
	while (*(s1 + start) && ft_ischarset(*(s1 + start), set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_ischarset(*(s1 + end - 1), set))
		end--;
	result = (char *)malloc(sizeof(char) * end - start + 1);
	if (!result)
		return ((void *)0);
	ft_strlcpy(result, (s1 + start), end - start + 1);
	return (result);
}
