/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:51:15 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/31 22:30:55 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long p)
{
	char	*str;
	int		count;

	str = "0123456789abcdef";
	count = 0;
	if (p >= 16)
	{
		count += ft_putptr(p / 16);
		count += ft_putchar(str[p % 16]);
	}
	else
		count += ft_putchar(str[p]);
	return (count);
}

int	ft_ptrptr(unsigned long p)
{
	if (!p)
	{
		return (write(1, "(nil)", 5));
	}
	ft_putstr("0x");
	return (ft_putptr(p) + 2);
}

// int main()
// {
// 	int result = ft_printf("%p", -1);
// 	ft_printf("%d",result);
// 	return 0;
// }
