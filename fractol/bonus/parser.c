/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:43:41 by jichompo          #+#    #+#             */
/*   Updated: 2024/07/18 13:43:42 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_dot(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '.')
			i++;
		str++;
	}
	return (i);
}

static int	check_float(char *str)
{
	int	i;

	if ((ft_strlen(str) == 1 && !ft_isdigit(str[0])) || check_dot(str) > 1)
		return (ft_printf("1\n"), 1);
	i = 0;
	if (*str == '+' || *str == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (ft_printf("2\n"), 1);
		if (str[i] == '.')
			if (ft_strlen((str + i)) > 7)
				return (ft_printf("3\n"), 1);
		i++;
	}
	return (0);
}

void	check_input(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
		my_exit(USAGE, NULL);
	if (argc == 2 && (ft_strcmp(argv[1], "Mandelbrot") != 0))
		my_exit(USAGE, NULL);
	if (argc == 4 && ft_strcmp(argv[1], "Julia"))
		my_exit(USAGE, NULL);
	if (argc == 4 && (check_float(argv[2]) || check_float(argv[3])))
		my_exit(USAGE, NULL);
}
