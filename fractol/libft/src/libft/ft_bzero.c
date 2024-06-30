/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:27:44 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/03 22:56:46 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	char			*p;
	unsigned int	index;

	index = 0;
	p = (char *)s;
	while (index < n)
	{
		*(p + index) = 0;
		index++;
	}
}
