/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:42:40 by jichompo          #+#    #+#             */
/*   Updated: 2024/07/18 13:42:42 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_struct(t_data *data)
{
	free(data->fractal);
	free(data);
}

void	my_exit(char *str, t_data *data)
{
	if (data)
		free_struct(data);
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
