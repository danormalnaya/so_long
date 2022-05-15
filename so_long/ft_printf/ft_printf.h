/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:57:08 by lloko             #+#    #+#             */
/*   Updated: 2021/12/05 16:37:05 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		print_char(char c);
int		print_string(char *str);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		print_base10_int(int n);
char	*ft_utoa(unsigned int n);
int		print_unsigned_int(unsigned int n);
int		print_base16(unsigned int numb, int type);
int		print_pointer(unsigned long n);
int		ft_printf(const char *in, ...);

#endif