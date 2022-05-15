/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:43:52 by lloko             #+#    #+#             */
/*   Updated: 2021/10/19 22:05:28 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answ;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	answ = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!answ)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		answ[j++] = s1[i++];
	i = 0;
	while (s2[i])
		answ[j++] = s2[i++];
	answ[j] = '\0';
	return (answ);
}
