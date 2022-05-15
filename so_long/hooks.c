/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:38 by lloko             #+#    #+#             */
/*   Updated: 2022/05/15 18:43:33 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	checkcol(t_game *carta, int y, int x)
{
	if (carta->map.arr[y][x] != '1')
	{
		if (carta->map.arr[y][x] == 'C')
		{
			carta->coll++;
			carta->c_count--;
			carta->map.arr[y][x] = '0';
		}
		if (carta->map.arr[y][x] == '0')
			carta->map.arr[y][x] = 'P';
		if (carta->map.arr[y][x] == 'E')
		{
			if (carta->c_count == 0)
			{
				ft_printf("You win! Your SCORE: %d\n", carta->coll);
				game_over(NULL);
				return (1);
			}
			else
				return (0);
		}
		ft_printf("Number of steps: %d\n", ++carta->step);
		return (1);
	}
	return (0);
}

static int	up_or_down(int keyboard, t_game *carta)
{
	if (keyboard == 13)
	{
		if (checkcol(carta, carta->player.player_y - 1, carta->player.player_x))
		{
			move_player(carta, carta->player.player_y, carta->player.player_x);
			carta->player.player_y -= 1;
		}
	}
	if (keyboard == 1)
	{
		if (checkcol(carta, carta->player.player_y + 1, carta->player.player_x))
		{
			move_player(carta, carta->player.player_y, carta->player.player_x);
			carta->player.player_y += 1;
		}
	}
	mlx_clear_window(carta->mlx, carta->win);
	paint(carta);
	return (0);
}

static int	left_or_right(int keyboard, t_game *carta)
{
	if (keyboard == 53)
	{
		mlx_destroy_window(carta->mlx, carta->win);
		game_over(NULL);
	}
	if (keyboard == 0)
	{
		if (checkcol(carta, carta->player.player_y, carta->player.player_x - 1))
		{
			move_player(carta, carta->player.player_y, carta->player.player_x);
			carta->player.player_x -= 1;
		}
	}
	if (keyboard == 2)
	{
		if (checkcol(carta, carta->player.player_y, carta->player.player_x + 1))
		{
			move_player(carta, carta->player.player_y, carta->player.player_x);
			carta->player.player_x += 1;
		}
	}
	mlx_clear_window(carta->mlx, carta->win);
	paint(carta);
	return (0);
}

static int	key_hook(int keyboard, t_game *carta)
{
	left_or_right(keyboard, carta);
	up_or_down(keyboard, carta);
	return (0);
}

void	move(t_game *carta)
{
	mlx_key_hook(carta->win, &key_hook, carta);
	mlx_hook(carta->win, 12, 0, &paint, carta);
	mlx_hook(carta->win, 17, 0, &game_over, NULL);
}
