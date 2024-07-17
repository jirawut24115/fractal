/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:35:58 by jichompo          #+#    #+#             */
/*   Updated: 2024/07/17 23:35:49 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_struct(t_data *data)
{
	free(data->fractal);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (-1);
	data = malloc(sizeof(t_data));
	//need parser checking first
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
