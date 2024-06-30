/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 01:40:26 by jichompo          #+#    #+#             */
/*   Updated: 2024/05/24 02:13:37 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **result)
{
	int	index;

	index = 0;
	while (result[index])
	{
		free(result[index]);
		index++;
	}
	free(result);
}