/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:52:35 by jalju-be          #+#    #+#             */
/*   Updated: 2025/08/31 21:38:17 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putnbr(int c);
int	ft_putstr(char *c);
int	ft_putunbr(unsigned int c);
int	ft_printf(const char *format, ...);
int	ft_putnbrhex(unsigned int nb, char format);
int	ft_ptrptr(unsigned long p);

#endif