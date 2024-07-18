/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:56:18 by jchompoo          #+#    #+#             */
/*   Updated: 2024/07/17 23:53:22 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_default_julia(t_data *data)
{
	data->scaled_min_x = -2;
	data->scaled_max_x = 2;
	data->scaled_min_y = -2;
	data->scaled_max_y = 2;
}

int	iteration_julia(int max, double x, double y, t_data *data)
{
	double	temp;
	int		i;

	i = 0;
	while (i <= max)
	{
		if (x * x + y * y > 4)
			return (i);
		temp = (x * x) - (y * y) + data->fractal->real;
		y = (2 * x * y) + data->fractal->img;
		x = temp;
		i++;
	}
	return (max);
}

void	julia(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x <= data->mlx->width)
	{
		y = 0;
		while (y <= data->mlx->height)
		{
			i = iteration_julia(data->iter, map(x, data, 'x'),
					map(y, data, 'y'), data);
			if (i == data->iter)
				mlx_put_pixel(data->img, x, y, 0x000000FF);
			else
				mlx_put_pixel(data->img, x, y, scale_color(i, data));
			y++;
		}
		x++;
	}
}
