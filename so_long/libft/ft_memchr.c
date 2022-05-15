/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:48:40 by lloko             #+#    #+#             */
/*   Updated: 2021/10/19 18:11:02 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		bite;
	const char	*sec;

	sec = (const char *)s;
	bite = (char)c;
	i = 0;
	while (i < n)
	{
		if (sec[i] == bite)
		{
			return ((char *)sec + i);
		}
		i++;
	}
	return (NULL);
}
