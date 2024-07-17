/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:28:42 by jchompoo          #+#    #+#             */
/*   Updated: 2024/07/17 23:32:56 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	scale_color(int iter, t_data *data)
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
	uint32_t	color;

	red = (uint32_t)(sin((double)iter) * 255 * data->color_scale);
	green = (uint32_t)(tan((double)iter) * 255 * data->color_scale);
	blue = (uint32_t)(cos((double)iter) * 255 * data->color_scale);
	color = (red << 24) | (green << 16) | (blue << 8) | 0x000000FF;
	if (color == 0x000000FF)
		color = 0xFFFFFFFF;
	return (color);
}

void	shift(t_data *data, char c)
{
	if (c == 'l')
	{
		data->scaled_max_x -= (0.5 * data->zoom);
		data->scaled_min_x -= (0.5 * data->zoom);
	}
	if (c == 'r')
	{
		data->scaled_max_x += (0.5 * data->zoom);
		data->scaled_min_x += (0.5 * data->zoom);
	}
	if (c == 'u')
	{
		data->scaled_max_y += (0.5 * data->zoom);
		data->scaled_min_y += (0.5 * data->zoom);
	}
	if (c == 'd')
	{
		data->scaled_max_y -= (0.5 * data->zoom);
		data->scaled_min_y -= (0.5 * data->zoom);
	}
}

double	map(int current, t_data *data, char c)
{
	if (c == 'x')
		return (data->scaled_min_x + (current / (double)data->mlx->width)
			* (data->scaled_max_x - data->scaled_min_x));
	else if (c == 'y')
		return (data->scaled_min_y + (current / (double)data->mlx->height)
			* (data->scaled_max_y - data->scaled_min_y));
	else
		return (0);
}
