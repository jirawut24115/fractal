/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:11:13 by jchompoo          #+#    #+#             */
/*   Updated: 2024/07/17 23:25:24 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keypress(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		shift(data, 'l');
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		shift(data, 'r');
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		shift(data, 'd');
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		shift(data, 'u');
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		set_default(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_M))
		set_iteration(data, '+');
	if (mlx_is_key_down(data->mlx, MLX_KEY_N))
		set_iteration(data, '-');
	if (mlx_is_key_down(data->mlx, MLX_KEY_C))
		set_color(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ENTER))
		printf("zoom = %.20lf \nx_offset = %.20lf\ny_offset = %.20lf\nscaled_min_x = %.20lf\nscaled_max_x = %.20lf\nscaled_min_y = %.20lf\nscaled_max_y = %.20lf\n------------------------------\n", data->zoom, data->x_offset, data->y_offset,\
	data->scaled_min_x, data->scaled_max_x, data->scaled_min_y, data->scaled_max_y);
}

void	general_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->fractal->name == 1)
		mandelbrot(data);
	if (data->fractal->name == 2)
		julia(data);
}

void	resize(int width, int height, void *param)
{
	(void)param;
	(void)width;
	(void)height;
}

static void	scale_zoom(t_data *data, double zoom_factor)
{
	data->scaled_min_x = data->x_offset
		- (data->x_offset - data->scaled_min_x) * zoom_factor;
	data->scaled_max_x = data->x_offset
		+ (data->scaled_max_x - data->x_offset) * zoom_factor;
	data->scaled_min_y = data->y_offset
		- (data->y_offset - data->scaled_min_y) * zoom_factor;
	data->scaled_max_y = data->y_offset
		+ (data->scaled_max_y - data->y_offset) * zoom_factor;
}

void	zoom(double xdel, double ydel, void *param)
{
	t_data	*data;
	int		x_pos;
	int		y_pos;
	double	zoom_factor;

	data = (t_data *)param;
	if (ydel > 0)
		zoom_factor = 1.1;
	else
		zoom_factor = 0.9;
	mlx_get_mouse_pos(data->mlx, &x_pos, &y_pos);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_CONTROL))
	{
		x_pos = data->mlx->width / 2;
		y_pos = data->mlx->height / 2;
	}
	if ((data->zoom > 1.0E-15 && ydel < 0) || (data->zoom < 500 && ydel > 0))
	{
		data->zoom *= zoom_factor;
		data->x_offset = map(x_pos, data, 'x');
		data->y_offset = map(y_pos, data, 'y');
		scale_zoom(data, zoom_factor);
	}
}
