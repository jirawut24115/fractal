/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:10:10 by jichompo          #+#    #+#             */
/*   Updated: 2024/05/20 20:26:26 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_type(int *result, const char *s, va_list ap)
{
	if (*s == 'c')
		*result += ft_putchar(va_arg(ap, int));
	if (*s == 's')
		*result += ft_putstr(va_arg(ap, char *));
	if (*s == 'd' || *s == 'i')
		*result += ft_print_num(va_arg(ap, int));
	if (*s == 'u')
		*result += ft_print_unsigned_num(va_arg(ap, unsigned int));
	if (*s == 'x' || *s == 'X')
		*result += ft_print_hex(va_arg(ap, unsigned int), *s);
	if (*s == 'p')
		*result += ft_print_ptr(va_arg(ap, void *));
	if (*s == '%')
		*result += write (1, "%", 1);
}

int	ft_printf(const char *s, ...)
{
	int		result;
	va_list	ap;

	result = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
		{
			result += write (1, s, 1);
			s++;
		}
		else
		{
			s++;
			ft_get_type(&result, s, ap);
			s++;
		}
	}
	va_end(ap);
	return (result);
}
