/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:57 by lloko             #+#    #+#             */
/*   Updated: 2021/10/31 18:57:08 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_string(const char *str, char a)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == a)
			i++;
		else
		{
			word++;
			while (str[i] != '\0' && str[i] != a)
				i++;
		}
	}
	return (word);
}

static char	*ft_create_word(const char *s, char b)
{
	int		i;
	char	*new;

	i = 0;
	while (*s && *s == b)
		s++;
	while (s[i] && s[i] != b)
		i++;
	new = (char *)malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != b)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void	ft_free(int i, char **arr)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**arr;

	if (!s)
		return (NULL);
	word = ft_string(s, c);
	arr = (char **)malloc((word + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < word)
	{
		while (*s && *s == c)
			s++;
		arr[i] = ft_create_word(s, c);
		if (!arr[i])
			ft_free(i, arr);
		while (*s && *s != c)
			s++;
		i++;
	}
	arr[i] = (NULL);
	return (arr);
}
