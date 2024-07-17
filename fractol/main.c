/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:35:58 by jichompo          #+#    #+#             */
/*   Updated: 2024/07/15 00:05:37 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double map(int current, t_data *data, char c)
{
    if (c == 'x')
        return (data->scaled_min_x + (current / (double)data->mlx->width) * (data->scaled_max_x - data->scaled_min_x));
    else if (c == 'y')
        return (data->scaled_min_y + (current / (double)data->mlx->height) * (data->scaled_max_y - data->scaled_min_y));
	else
		return (0);
}

int	find_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

double	ft_atof(char *str)
{
	double	whole;
	double	dec;
	double		sign;
	double		i;

	sign = find_sign((*str));
	if (sign == -1)
		str++;
	whole = 0;
	while (*(str) && *(str) != '.')
	{
		whole = whole * 10 + (*(str) - '0');
		str++;
	}
	if (*str)
		str++;
	dec = 0;
	i = 1;
	while (*str)
	{
		i /= 10;
		dec = dec * 10 + (*(str) - '0');
		str++;
	}
	return ((whole + (dec * i)) * sign);	
}

t_fractal	*set_fractal(int argc, char **argv)
{
	t_fractal	*result;

	result = malloc(sizeof(t_fractal));	
	if (argc == 2 && !ft_strcmp(argv[1], "Mandelbrot"))
	{
		result->name = 1; // 1 = mandelbrot
		result->real = 0;
		result->img = 0;
		result->error = 0;
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
	{
		result->name = 2; // 2 = julia
		result->real = ft_atof(argv[2]); // need to change to atof
		result->img = ft_atof(argv[3]); // need to change to atof
		result->error = 0;
	}
	else
		result->error = 1;
	return (result);
}

void	free_struct(t_data *data)
{
	free(data->fractal);
	free(data);
}

// uint32_t scale_color(int iter, t_data *data)
// {
//     unsigned int color;
//     double ratio = (double)iter / data->color_scale; // Calculate ratio based on iter and color_scale

//     // Adjust color based on the ratio and a maximum value (0xFFFFFF)
//     color = (unsigned int)(ratio * 0xFFFFFF);

//     // Ensure color does not exceed the maximum possible value
//     if (color > 0xFFFFFF) {
//         color = 0xFFFFFF;
//     }

//     // Optionally, you can add an alpha channel (transparency) here if needed
//     // Example: color |= 0xFF000000; // Add alpha channel (fully opaque)

//     // Return the calculated color
//     return (color |= 0x000000FF);
// }

// uint32_t scale_color(int iter, t_data *data)
// {
//     unsigned int color;
//     double ratio = (double)iter / data->color_scale; // adjust this value to change the color range
//     color = (unsigned int)(ratio * 0xFFFFFF); // add alpha channel
// 	color /= iter;
//     return ((uint32_t) 0xFF00FFFF);
// }

uint32_t	scale_color(int iter, t_data *data)
{
	unsigned int	color;
	double			ratio;

	ratio = iter / data->color_scale;
	color = (unsigned int)(0xFF000000 * ratio / 7) | (unsigned int)(0x00FF0000 * ratio / 3) | (unsigned int)(0x0000FF00 * ratio / 5) | 0x000000FF;
	return (color);
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
			i = iteration_mandelbrot(data->iter, map(x, data, 'x'), map(y, data, 'y'));
			if (i == data->iter)
				mlx_put_pixel(data->img, x, y, 0xFFFFFFFF);
			else
				mlx_put_pixel(data->img, x, y, scale_color(i, data));
			y++;
		}
	x++;
	}
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
			i = iteration_julia(data->iter, map(x, data, 'x'), map(y, data, 'y'), data);
			if (i == data->iter)
				mlx_put_pixel(data->img, x, y, 0xFFFFFFFF);
			else
				mlx_put_pixel(data->img, x, y, scale_color(i, data));
			y++;
		}
		x++;
	}
}
void	set_default_mandelbrot(t_data *data)
{
	data->scaled_min_x = -2.5;
	data->scaled_max_x = 1.5;
	data->scaled_min_y = -2;
	data->scaled_max_y = 2;
}
void	set_default_julia(t_data *data)
{
	data->scaled_min_x = -2;
	data->scaled_max_x = 2;
	data->scaled_min_y = -2;
	data->scaled_max_y = 2;
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
	data->color_scale = 0;
}

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

void	shift(t_data *data, char c)
{
	if (c == 'l')
	{
		data->scaled_max_x -= (0.1 * data->zoom);
		data->scaled_min_x -= (0.1 * data->zoom);
	}
	if (c == 'r')
	{
		data->scaled_max_x += (0.1 * data->zoom);
		data->scaled_min_x += (0.1 * data->zoom);
	}
	if (c == 'u')
	{
		data->scaled_max_y += (0.1 * data->zoom);
		data->scaled_min_y += (0.1 * data->zoom);
	}
	if (c == 'd')
	{
		data->scaled_max_y -= (0.1 * data->zoom);
		data->scaled_min_y -= (0.1 * data->zoom);
	}
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
		data->color_scale += 500;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ENTER))
		printf("zoom = %.20lf \nx_offset = %.20lf\ny_offset = %.20lf\nscaled_min_x = %.20lf\nscaled_max_x = %.20lf\nscaled_min_y = %.20lf\nscaled_max_y = %.20lf\n------------------------------\n", data->zoom, data->x_offset, data->y_offset,\
	data->scaled_min_x, data->scaled_max_x, data->scaled_min_y, data->scaled_max_y);
}

void zoom(double xdel, double ydel, void *param)
{
    t_data *data = (t_data *)param;
    int x_pos;
    int y_pos;
    double zoom_factor;

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
	if ((data->zoom > 0.000000000000001 && ydel < 0) || (data->zoom < 500 && ydel > 0))
	{
		data->zoom *= zoom_factor;
		data->x_offset = map(x_pos, data, 'x');
	    data->y_offset = map(y_pos, data, 'y');
		data->scaled_min_x = data->x_offset - (data->x_offset - data->scaled_min_x) * zoom_factor;
	    data->scaled_max_x = data->x_offset + (data->scaled_max_x - data->x_offset) * zoom_factor;
	    data->scaled_min_y = data->y_offset - (data->y_offset - data->scaled_min_y) * zoom_factor;
	    data->scaled_max_y = data->y_offset + (data->scaled_max_y - data->y_offset) * zoom_factor;
	}
}


void	general_hook(void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (data->fractal->name == 1)
		mandelbrot(data);
	if (data->fractal->name == 2)
		julia(data);
}
void	resize(int width, int height, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	printf("%d %d\n",width, height);
	data->mlx->width = width;
	data->mlx->height = height;
}


int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (-1);
	data = malloc(sizeof(t_data));
	data->fractal = set_fractal(argc, argv);
	if (data->fractal->error)
		return (free_struct(data), ft_printf("Invalid arg\n"), 0);
	initialize(data);
	mlx_key_hook(data->mlx, &keypress, (void *)data);
	mlx_scroll_hook(data->mlx, zoom, (void *)data);
	mlx_resize_hook(data->mlx, resize, (void *)data);
	mlx_loop_hook(data->mlx, general_hook, (void *)data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_struct(data);
}
