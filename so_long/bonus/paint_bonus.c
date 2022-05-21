/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:35:19 by lloko             #+#    #+#             */
/*   Updated: 2022/05/21 14:18:18 by lloko            ###   ########.fr       */
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
			"image/wall.xpm", &w, &h);
	carta->sprite.background = mlx_xpm_file_to_image(carta->mlx,
			"image/background.xpm", &w, &h);
	carta->sprite.exit = mlx_xpm_file_to_image(carta->mlx,
			"image/exit.xpm", &w, &h);
	carta->sprite.collect = mlx_xpm_file_to_image(carta->mlx,
			"image/heart.xpm", &w, &h);
	carta->player.move_pl = mlx_xpm_file_to_image(carta->mlx,
			"image/player.xpm", &w, &h);
	carta->sprite.vrag = mlx_xpm_file_to_image(carta->mlx,
			"image/vrag.xpm", &w, &h);
	if (!carta->sprite.wall || !carta->sprite.background || !carta->sprite.exit
		|| !carta->sprite.collect || !carta->player.move_pl
		|| !carta->sprite.vrag)
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
					carta->sprite.vrag, c * SPRITE, r * SPRITE);
		}
		r++;
	}
	printf("gotovo");
}

int	paint(t_game *carta)
{
	push_image_from_file(carta);
	draw_items(carta);
	draw_player_and_collect(carta);
	return (0);
}
