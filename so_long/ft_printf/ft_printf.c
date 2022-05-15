/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:42:23 by lloko             #+#    #+#             */
/*   Updated: 2021/12/08 18:30:04 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	myprint(const char *s, va_list ap)
{
	if (*s == 'c')
		return (print_char(va_arg(ap, int)));
	else if (*s == 's')
		return (print_string(va_arg(ap, char *)));
	else if (*s == 'p')
	{
		print_string("0x");
		return (2 + print_pointer(va_arg(ap, unsigned long)));
	}
	else if (*s == 'd' || *s == 'i')
		return (print_base10_int(va_arg(ap, int)));
	else if (*s == 'u')
		return (print_unsigned_int(va_arg(ap, unsigned int)));
	else if (*s == 'x')
		return (print_base16(va_arg(ap, unsigned int), 0));
	else if (*s == 'X')
		return (print_base16(va_arg(ap, unsigned int), 1));
	else if (*s == '%')
		return (print_char('%'));
	return (0);
}

int	parser(const char *str, va_list ap)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += myprint(str, ap);
		}
		else
		{
			print_char(*str);
			i++;
		}
		str++;
	}
	return (i);
}

int	ft_printf(const char *in, ...)
{
	int		k;
	va_list	ap;

	va_start(ap, in);
	k = parser(in, ap);
	va_end(ap);
	return (k);
}
