/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_vrag_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:20:21 by lloko             #+#    #+#             */
/*   Updated: 2022/05/15 20:04:52 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_vrag(char **map, t_game *carta)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'V')
				carta->v_count++;
		}
	}
	if (carta->v_count < 1)
		return (1);
	return (0);
}
