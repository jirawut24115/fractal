/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:35:58 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/03 15:36:00 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		result->real = ft_atoi(argv[2]); // need to change to atof
		result->img = ft_atoi(argv[3]); // need to change to atof
		result->error = 0;
	}
	else
		result->error = 1;
	return (result);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
		return (-1);
	fractal = set_fractal(argc, argv);
	if (fractal->error)
		return (free(fractal), ft_printf("Invalid arg\n"), 0);
	ft_printf("name = %d | real = %d | img = %d\n", fractal->name, fractal->real, fractal->img);
	free(fractal);
}
