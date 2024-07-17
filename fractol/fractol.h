/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:53 by jichompo          #+#    #+#             */
/*   Updated: 2024/07/17 22:13:21 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "MLX42.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_fractal
{
	int		name; // 1 = mandelbrot 2 = Julia 3 = bonus
	double	real;
	double	img;
	int		error;
}	t_fractal;

typedef struct s_data
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	t_fractal	*fractal;
	double	zoom;
	double	x_offset;
	double	y_offset;
	double	scaled_min_x;
	double	scaled_max_x;
	double	scaled_min_y;
	double	scaled_max_y;
	int		iter;
	double	color_scale;
}	t_data;

#endif