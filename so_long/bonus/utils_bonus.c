/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:32:25 by lloko             #+#    #+#             */
/*   Updated: 2022/05/22 19:19:47 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	game_over(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		exit(1);
	}
	exit(0);
}

int	move_player(t_game *carta, int y, int x)
{
	carta->map.arr[y][x] = '0';
	return (0);
}

void	touch_vrag(t_game *carta)
{
	t_vrag	*tmp;

	tmp = carta->vrag;
	while (tmp)
	{
		if (tmp->vrag_y == carta->player.player_y
			&& tmp->vrag_x == carta->player.player_x)
			game_over("You touch enemy!\n");
		tmp = tmp->next;
	}
}
