/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:52:41 by jchompoo          #+#    #+#             */
/*   Updated: 2024/07/17 23:40:04 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_default_mandelbrot(t_data *data)
{
	data->scaled_min_x = -2.5;
	data->scaled_max_x = 1.5;
	data->scaled_min_y = -2;
	data->scaled_max_y = 2;
}

int	iteration_mandelbrot(int max, double x, double y)
{
	double	new_x;
	double	new_y;
	double	temp;
	int		i;

	new_x = x;
	new_y = y;
	i = 0;
	while (i <= max)
	{
		temp = (new_x * new_x) - (new_y * new_y) + x;
		new_y = (2 * new_x * new_y) + y;
		new_x = temp;
		if (new_x * new_x + new_y * new_y > 4)
			return (i);
		i++;
	}
	return (max);
}

void	mandelbrot(t_data *data)
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
			i = iteration_mandelbrot(data->iter, map(x, data, 'x'),
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
