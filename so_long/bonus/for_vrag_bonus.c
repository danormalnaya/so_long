/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_vrag_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:20:21 by lloko             #+#    #+#             */
/*   Updated: 2022/05/22 19:06:52 by lloko            ###   ########.fr       */
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
			{
				carta->v_count++;
				add_enem(carta, i, j);
			}
		}
	}
	if (carta->v_count < 1)
		return (1);
	return (0);
}

void	anim_vrag(t_game *carta)
{
	static int	i;

	if (i == carta->sprite.anim)
		carta->sprite.cur = carta->sprite.vrag_0;
	else if (i == carta->sprite.anim * 2)
		carta->sprite.cur = carta->sprite.vrag_1;
	else if (i == carta->sprite.anim * 3)
		carta->sprite.cur = carta->sprite.vrag_2;
	else if (i == carta->sprite.anim * 4)
	{
		carta->sprite.cur = carta->sprite.vrag_3;
		i = 0;
	}
	i++;
}

static void	vr_left(t_vrag *vr, t_game *carta)
{
	if (carta->map.arr[vr->vrag_y][vr->vrag_x - 1] == '0')
	{
		carta->map.arr[vr->vrag_y][vr->vrag_x] = '0';
		carta->map.arr[vr->vrag_y][vr->vrag_x - 1] = 'V';
	}
	else if (carta->map.arr[vr->vrag_y][vr->vrag_x - 1] == '1'
			|| carta->map.arr[vr->vrag_y][vr->vrag_x - 1] == 'C')
		vr->dir = 0;
	(vr->vrag_x)--;
}

static void	vr_right(t_vrag *vr, t_game *carta)
{
	if (carta->map.arr[vr->vrag_y][vr->vrag_x + 1] == '0')
	{
		carta->map.arr[vr->vrag_y][vr->vrag_x] = '0';
		carta->map.arr[vr->vrag_y][vr->vrag_x + 1] = 'V';
	}
	else if (carta->map.arr[vr->vrag_y][vr->vrag_x + 1] == '1'
			|| carta->map.arr[vr->vrag_y][vr->vrag_x + 1] == 'C')
		vr->dir = 1;
	(vr->vrag_x)++;
}

void	move_enemy(t_game *carta)
{
	t_vrag	*tmp;

	tmp = carta->vrag;
	while (tmp)
	{
		if (tmp->dir == 0)
			vr_right(tmp, carta);
		else
			vr_left(tmp, carta);
		tmp = tmp->next;
	}
}
