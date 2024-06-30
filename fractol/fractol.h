/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:53 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/03 15:36:55 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_fractal
{
	int		name; // 1 = mandelbrot 2 = Julia 3 = bonus
	float	real;
	float	img;
	int		error;
}	t_fractal;

#endif