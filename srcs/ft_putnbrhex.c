/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:43:29 by jalju-be          #+#    #+#             */
/*   Updated: 2025/09/03 03:35:16 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhex(unsigned int nbr, char format)
{
	char	*str;
	int		i;

	if (format == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	i = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr >= 16)
	{
		i += ft_putnbrhex(nbr / 16, format);
		i += ft_putchar(str[nbr % 16]);
	}
	else
		i += ft_putchar(str[nbr]);
	return (i);
}
