/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:54:18 by lloko             #+#    #+#             */
/*   Updated: 2021/10/17 17:06:47 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = 0;
	i = 0;
	while (dst[dlen] && dlen < dstsize)
	{
		dlen++;
	}
	while (src[i] && (i + dlen + 1) < dstsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	if (dstsize > dlen)
		dst[dlen + i] = '\0';
	return (slen + ft_min(dstsize, dlen));
}
