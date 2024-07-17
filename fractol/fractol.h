/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:53 by jichompo          #+#    #+#             */
/*   Updated: 2024/07/14 23:57:59 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "MLX42.h"


typedef struct s_fractal
{
	int		name; // 1 = mandelbrot 2 = Julia 3 = bonus
	float	real;
	float	img;
	int		error;
}	t_fractal;

typedef struct s_data
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	t_fractal	*fractal;
	float	zoom;
	float	x_offset;
	float	y_offset;
	float	scaled_min_x;
	float	scaled_max_x;
	float	scaled_min_y;
	float	scaled_max_y;
	int		iter;
	float	color_scale;
}	t_data;

#endif