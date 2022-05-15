/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:24:21 by lloko             #+#    #+#             */
/*   Updated: 2021/10/19 21:30:14 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	size_t	a;
	size_t	lench;

	lench = ft_strlen(s1);
	c = (char *)malloc(lench + 1);
	if (!c)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		c[a] = s1[a];
		a++;
	}
	c[a] = '\0';
	return (c);
}
