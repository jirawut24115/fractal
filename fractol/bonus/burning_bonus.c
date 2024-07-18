/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:45:47 by jichompo          #+#    #+#             */
/*   Updated: 2024/07/18 18:45:49 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	set_default_burning(t_data *data)
{
	data->scaled_min_x = -2;
	data->scaled_max_x = 2;
	data->scaled_min_y = -2;
	data->scaled_max_y = 2;
}

int	iteration_burning(int max, double x, double y)
{
	double	new_x;
	double	new_y;
	double	temp;
	int		i;

	new_x = 0;
	new_y = 0;
	i = 0;
	while (i <= max)
	{
		if (new_x * new_x + new_y * new_y > 4)
			return (i);
		temp = (new_x * new_x) - (new_y * new_y) + x;
		new_y = fabs((2 * new_x * new_y)) + y;
		new_x = fabs(temp);
		i++;
	}
	return (max);
}

void	burning(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < data->mlx->width)
	{
		y = 0;
		while (y < data->mlx->height)
		{
			i = iteration_burning(data->iter, map(x, data, 'x'),
					map(y, data, 'y'));
			if (i == data->iter)
				mlx_put_pixel(data->img, x, y, 0x000000FF);
			else
				mlx_put_pixel(data->img, x, y, scale_color(i, data));
			y++;
		}
		x++;
	}
}
