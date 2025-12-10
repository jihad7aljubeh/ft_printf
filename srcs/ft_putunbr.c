/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:44:31 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/31 20:44:33 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int c)
{
	char	a;
	int		len;

	len = 0;
	if (c > 9)
		len += ft_putunbr(c / 10);
	a = (c % 10) + '0';
	len += write(1, &a, 1);
	return (len);
}
// int main(void)
// {
//     printf("\n\n\n%d",ft_putunbr(0));
//     return (0);
// }