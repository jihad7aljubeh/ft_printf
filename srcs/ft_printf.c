/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:01:36 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/31 21:37:25 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_format_handler(const char *format, int i, va_list ap)
{
	if (format[i] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format[i] == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (format[i] == 'p')
		return (ft_ptrptr(va_arg(ap, unsigned long)));
	else if (format[i] == 'x' || format[i] == 'X')
		return (ft_putnbrhex(va_arg(ap, unsigned int), format[i]));
	else if (format[i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	int		count;

	count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format_handler(format, i, ap);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
