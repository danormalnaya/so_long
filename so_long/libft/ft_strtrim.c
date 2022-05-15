/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:08:27 by lloko             #+#    #+#             */
/*   Updated: 2021/10/27 15:32:24 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	cut;
	size_t	i;
	char	*new;

	if (!s1)
		return (NULL);
	cut = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[cut - 1]) && cut > i)
		cut--;
	new = (char *)malloc(cut - i + 1);
	if (!new)
		return (NULL);
	if (new)
		ft_strlcpy(new, &s1[i], cut - i + 1);
	return (new);
}
