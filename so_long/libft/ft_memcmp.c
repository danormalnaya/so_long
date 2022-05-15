/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:27:37 by lloko             #+#    #+#             */
/*   Updated: 2021/10/19 18:12:15 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			i;

	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (arr1[i] == arr2[i])
		{
			n--;
			i++;
		}
		else
			return (arr1[i] - arr2[i]);
	}
	return (0);
}
