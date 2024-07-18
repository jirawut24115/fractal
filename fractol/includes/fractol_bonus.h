/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:53 by jichompo          #+#    #+#             */
/*   Updated: 2024/07/17 23:37:15 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define USAGE "For Mandelbrot set: ./fractol Mandelbrot\n\
For Julia set: ./fractol Julia <real> <imaginary>\n\
<real> <imaginary> can be up to 6 decimal points.\n\
For example and nice recommendation\n\
./fractol Julia 0.285000 0.01\n\
./fractal Julia -0.8 0.156\n\
./fractol Julia 0.35 0.35"
# define MLX_ERROR "There's something wrong with MLX."
# define HELP "Options:\n\
KEY_C : Change color scale.\n\
KEY_M : Increase iteration by 10(Max: 420 iterations)\n\
KEY_N : Decrease iteration by 10(Min: 50 iterations)\n\
ARROW_KEYS : Move around\n\
KEY_SPACE : Reset to default\n\
KEY_ESC : Exit\n\
SCROLL_UP_DOWN : Zoom in and out according to mouse position\n\
LEFT_CTRL + SCROLL_UP_DOWN : Zoom in and out towards center of window\n"

typedef struct s_fractal
{
	int		name;
	double	real;
	double	img;
	int		error;
}	t_fractal;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractal	*fractal;
	double		zoom;
	double		x_offset;
	double		y_offset;
	double		scaled_min_x;
	double		scaled_max_x;
	double		scaled_min_y;
	double		scaled_max_y;
	int			iter;
	double		color_scale;
}	t_data;

//mandelbrot
int			iteration_mandelbrot(int max, double x, double y);
void		mandelbrot(t_data *data);
void		set_default_mandelbrot(t_data *data);

//julia
void		set_default_julia(t_data *data);
int			iteration_julia(int max, double x, double y, t_data *data);
void		julia(t_data *data);

//initialize
void		initialize(t_data *data);
void		set_default(t_data *data);
void		set_iteration(t_data *data, char c);
void		set_color(t_data *data);
t_fractal	*set_fractal(int argc, char **argv);

//hooks
void		keypress(mlx_key_data_t keydata, void *param);
void		general_hook(void *param);
void		resize(int width, int height, void *param);
void		zoom(double xdel, double ydel, void *param);

//utils
uint32_t	scale_color(int iter, t_data *data);
void		shift(t_data *data, char c);
double		map(int current, t_data *data, char c);

//atof
double		ft_atof(char *str);

//exit
void		my_exit(char *str, t_data *data);
void		free_struct(t_data *data);

//parser
void		check_input(int argc, char **argv);

//bonus
void		set_default_burning(t_data *data);
int			iteration_burning(int max, double x, double y);
void		burning(t_data *data);

#endif