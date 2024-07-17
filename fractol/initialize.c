/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:02:16 by jchompoo          #+#    #+#             */
/*   Updated: 2024/07/17 23:08:33 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize(t_data *data)
{
	data->mlx = mlx_init(3840, 2075, "Fractals", true);
	if (!data->mlx)
		return ; // handle error
	data->img = mlx_new_image(data->mlx, data->mlx->width, data->mlx->width);
	if (!data->img)
		return ; // handle error
	set_default(data);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		return ;//handle error
}

void	set_default(t_data *data)
{
	data->zoom = 1;
	data->x_offset = 0;
	data->y_offset = 0;
	if (data->fractal->name == 1)
		set_default_mandelbrot(data);
	if (data->fractal->name == 2)
		set_default_julia(data);
	data->iter = 50;
	data->color_scale = 0.01;
}

void	set_iteration(t_data *data, char c)
{
	if (c == '+' && data->iter <= 420)
		data->iter += 10;
	else if (data->iter >= 420 && c == '+')
		ft_printf("Iteration at max.\n");
	else if (c == '-' && data->iter > 50)
		data->iter -= 10;
	else
		ft_printf("Iteration at min.\n");
}

void	set_color(t_data *data)
{
	if (data->color_scale < 1)
		data->color_scale += 0.01;
	else
		data->color_scale = 0.01;
}

t_fractal	*set_fractal(int argc, char **argv)
{
	t_fractal	*result;

	result = malloc(sizeof(t_fractal));
	if (argc == 2 && !ft_strcmp(argv[1], "Mandelbrot"))
	{
		result->name = 1;
		result->real = 0;
		result->img = 0;
		result->error = 0;
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
	{
		result->name = 2;
		result->real = ft_atof(argv[2]);
		result->img = ft_atof(argv[3]);
		result->error = 0;
	}
	else
		result->error = 1;
	return (result);
}
