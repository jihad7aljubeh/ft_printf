/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:43:14 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/31 21:02:13 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int c)
{
	int	count;

	count = 0;
	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	if (c < 0)
	{
		count += ft_putchar('-');
		c = c * -1;
	}
	if (c > 9)
		count += ft_putnbr(c / 10);
	count += ft_putchar(c % 10 + '0');
	return (count);
}
