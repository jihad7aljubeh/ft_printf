/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:39:15 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/31 21:11:28 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>
int	ft_putstr(char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!c)
	{
		return (write(1, "(null)", 6));
	}
	while (c[i] != '\0')
	{
		count += write(1, &c[i], 1);
		i++;
	}
	return (count);
}

// int main()
// {
// 	int i = ft_printf("%s", "-");
// 	ft_printf("%d", i);
// }
