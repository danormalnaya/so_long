/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:19:10 by lloko             #+#    #+#             */
/*   Updated: 2022/05/22 19:19:28 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_en_lst(t_game *carta)
{
	t_vrag	*tmp;

	while (carta->vrag)
	{
		tmp = carta->vrag->next;
		free(carta->vrag);
		carta->vrag = tmp;
	}
}

static t_vrag	*new_enemy(int r, int c)
{
	t_vrag	*enem;

	enem = malloc(sizeof(t_vrag));
	if (!enem)
		return (NULL);
	enem->vrag_y = r;
	enem->vrag_x = c;
	enem->dir = 0;
	enem->next = NULL;
	return (enem);
}

void	add_enem(t_game *carta, int r, int c)
{
	t_vrag	*enem;

	enem = new_enemy(r, c);
	if (!enem)
	{
		free(carta->map.arr);
		clean_en_lst(carta);
		game_over("Enemy alloc error.\n");
	}
	enem->next = carta->vrag;
	carta->vrag = enem;
}
