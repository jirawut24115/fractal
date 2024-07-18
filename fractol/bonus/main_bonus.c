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

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	check_input(argc, argv);
	data = malloc(sizeof(t_data));
	data->fractal = set_fractal(argc, argv);
	initialize(data);
	mlx_key_hook(data->mlx, &keypress, (void *)data);
	mlx_scroll_hook(data->mlx, zoom, (void *)data);
	mlx_resize_hook(data->mlx, resize, (void *)data);
	mlx_loop_hook(data->mlx, general_hook, (void *)data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_struct(data);
}
