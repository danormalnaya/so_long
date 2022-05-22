/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:35:19 by lloko             #+#    #+#             */
/*   Updated: 2022/05/22 19:09:47 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	push_image_from_file(t_game *carta)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	carta->sprite.wall = mlx_xpm_file_to_image(carta->mlx,
			"bonus/image/wall.xpm", &w, &h);
	carta->sprite.background = mlx_xpm_file_to_image(carta->mlx,
			"bonus/image/background.xpm", &w, &h);
	carta->sprite.exit = mlx_xpm_file_to_image(carta->mlx,
			"bonus/image/exit.xpm", &w, &h);
	carta->sprite.collect = mlx_xpm_file_to_image(carta->mlx,
			"bonus/image/heart.xpm", &w, &h);
	carta->player.move_pl = mlx_xpm_file_to_image(carta->mlx,
			"bonus/image/player.xpm", &w, &h);
	if (!carta->sprite.wall || !carta->sprite.background || !carta->sprite.exit
		|| !carta->sprite.collect || !carta->player.move_pl)
	{
		free(carta->map.arr);
		game_over("Image didn't load!\n");
	}
}

void	push_image_vrag(t_game *carta)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	carta->sprite.vrag_0 = mlx_xpm_file_to_image(carta->mlx,
			"bonus/image/vrag_0.xpm", &w, &h);
	carta->sprite.vrag_1 = mlx_xpm_file_to_image(carta->mlx,
			"bonus/image/vrag_1.xpm", &w, &h);
	carta->sprite.vrag_2 = mlx_xpm_file_to_image(carta->mlx,
			"bonus/image/vrag_2.xpm", &w, &h);
	carta->sprite.vrag_3 = mlx_xpm_file_to_image(carta->mlx,
			"bonus/image/vrag_3.xpm", &w, &h);
	carta->sprite.cur = carta->sprite.vrag_0;
	if (!carta->sprite.vrag_0 || !carta->sprite.vrag_1 || !carta->sprite.vrag_2
		|| !carta->sprite.vrag_3)
	{
		free(carta->map.arr);
		game_over("Image didn't load!\n");
	}
}

static void	draw_items(t_game *carta)
{
	int	c;
	int	r;

	r = 0;
	while (r < carta->map.y)
	{
		c = -1;
		while (++c < carta->map.x)
		{
			if (carta->map.arr[r][c] == '1')
				mlx_put_image_to_window(carta->mlx, carta->win,
					carta->sprite.wall, c * SPRITE, r * SPRITE);
			else if (carta->map.arr[r][c] == 'E')
				mlx_put_image_to_window(carta->mlx, carta->win,
					carta->sprite.exit, c * SPRITE, r * SPRITE);
			else if (carta->map.arr[r][c] == '0' || carta->map.arr[r][c] == 'P'
					|| carta->map.arr[r][c] == 'C'
					|| carta->map.arr[r][c] == 'V')
				mlx_put_image_to_window(carta->mlx, carta->win,
					carta->sprite.background, c * SPRITE, r * SPRITE);
		}
		r++;
	}
}

static void	draw_player_and_collect(t_game *carta)
{
	int	c;
	int	r;

	r = 0;
	while (r < carta->map.y)
	{
		c = -1;
		while (++c < carta->map.x)
		{
			if (carta->map.arr[r][c] == 'P')
				mlx_put_image_to_window(carta->mlx, carta->win,
					carta->player.move_pl, c * SPRITE, r * SPRITE);
			else if (carta->map.arr[r][c] == 'C')
				mlx_put_image_to_window(carta->mlx, carta->win,
					carta->sprite.collect, c * SPRITE, r * SPRITE);
			else if (carta->map.arr[r][c] == 'V')
				mlx_put_image_to_window(carta->mlx, carta->win,
					carta->sprite.cur, c * SPRITE, r * SPRITE);
		}
		r++;
	}
}

int	paint(t_game *carta)
{
	char	*str;

	draw_items(carta);
	draw_player_and_collect(carta);
	anim_vrag(carta);
	touch_vrag(carta);
	if (carta->move_vr == 50)
	{
		carta->move_vr = 0;
		move_enemy(carta);
	}
	carta->move_vr++;
	str = ft_itoa(carta->step);
	mlx_string_put(carta->mlx, carta->win, 0, 0, 000000, "STEP PLAYER:");
	mlx_string_put(carta->mlx, carta->win, 128, 0, 000000, str);
	free(str);
	return (0);
}
