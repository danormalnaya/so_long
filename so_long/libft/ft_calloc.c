/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:11:02 by lloko             #+#    #+#             */
/*   Updated: 2021/10/24 15:11:06 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	a;

	a = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (a < count * size)
	{
		str[a] = 0;
		a++;
	}
	return (str);
}
