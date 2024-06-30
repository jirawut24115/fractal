/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:04:25 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/04 10:26:34 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	size_t	str_len;
	char	*result;

	str_len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * str_len + 1);
	if (!result)
		return ((void *)0);
	ft_strlcpy(result, str, str_len + 1);
	*(result + str_len) = '\0';
	return (result);
}
