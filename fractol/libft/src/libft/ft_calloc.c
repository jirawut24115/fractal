/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:57:25 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/08 21:14:43 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buff;

	if (count * size > 2147483647)
		return ((void *)0);
	buff = (void *)malloc(size * count);
	if (!buff)
		return (NULL);
	ft_bzero(buff, size * count);
	return (buff);
}
